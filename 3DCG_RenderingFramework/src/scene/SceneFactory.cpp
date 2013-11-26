#include "SceneFactory.h"
#include "Point.h"
#include "Colour.h"
#include "Sphere.h"
#include "Mesh.h"
#include "ScaleTransfo.h"
#include "TranslateTransfo.h"
#include "RotateTransfo.h"
#include "TransfoStack.h"
#include "Transfo.h"
#include "Square.h"
#include <iostream>

Scene SceneFactory::createScene(const std::string & filename){

	Scene scene;
	Material currMtrl;
    TransfoStack stack;

	std::ifstream inf(filename.c_str());
	if (!inf) {
		std::cout << "SDL file " << filename << " could not be opened!\n";
		exit(1);
	}

	while(inf){
		std::string key;
		inf >> key;
        
		if(key.empty()){
			continue;
		}
        
		if(key.compare("background")==0){
            
			double r,g,b;
			inf >> r >> g >> b;
			scene.setBackground(Colour(r,g,b));
                        
		} else if (key.compare("light")==0) {

			double x,y,z,r,g,b;
			inf >> x >> y >> z >> r >> g >> b;

			Point pos(x,y,z);
			Colour col(r,g,b);
			Light *light = new Light(pos, col);

			scene.addLight(light);

		} else if(!processMaterial(inf, key, currMtrl)){
            if(!processTransfo(inf, key, stack)) {
                
                scene.addObject(createShape(inf, key, currMtrl, stack.top()));

            }
		}
	}
	return scene;
}


bool SceneFactory::processMaterial(std::ifstream & inf, const std::string & key, Material & currMtrl){
	if(key.compare("diffuse")==0){
		double r,g,b;
		inf >> r >> g >> b;
		currMtrl.setDiffuse(Colour(r,g,b));
		return true;
	} else if (key.compare("ambient")==0) {
		double r,g,b;
		inf >> r >> g >> b;
		currMtrl.setAmbient(Colour(r,g,b));
		return true;
	}
	return false;
}

bool SceneFactory::processTransfo(std::ifstream & inf, const std::string & key, TransfoStack & stack){
    if (key.compare("scale")==0) {
        double sx, sy, sz;
        inf >> sx >> sy >> sz;
        stack.transform(ScaleTransfo(sx, sy, sz));
        return true;
    } else if (key.compare("translate")==0) {
        double tx, ty, tz;
        inf >> tx >> ty >> tz;
        stack.transform(TranslateTransfo(tx, ty, tz));
        return true;
    } else if (key.compare("rotate")==0) {
        double angle, rx, ry, rz;
        inf >> angle >> rx >> ry >> rz;
        stack.transform(RotateTransfo(angle, rx, ry, rz));
        return true;
    } else if (key.compare("push")==0) {
        stack.push();
        return true;
    } else if (key.compare("pop")==0) {
        stack.pop();
        return true;
    }
    
    return false;
}

Shape * SceneFactory::createShape(std::ifstream & inf, const std::string & key, const Material & currMtrl, const Transfo & currTransfo){
	Shape * shape;
	if(key.compare("sphere")==0){
		shape = new Sphere;
    } else if(key.compare("square")==0){
		shape = new Square;
	} else if(key.compare("mesh")==0){
        std::string path;
        inf >> path;
        shape = new Mesh(path);
    } else {
		std::cout << "Token " << key << " in SDL file is not supported!\n";
		exit(1);
	}
	shape->setMaterial(Material(currMtrl));
    shape->setTransfo(Transfo(currTransfo));
	return shape;
}
