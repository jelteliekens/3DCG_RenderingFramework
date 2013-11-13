#ifndef SCENEFACTORY_H_
#define SCENEFACTORY_H_

#include <string>
#include <fstream>
#include "Material.h"
#include "Shape.h"
#include "Scene.h"
#include "Transfo.h"
#include "TransfoStack.h"

class SceneFactory {

	static bool processMaterial(std::ifstream & inf, const std::string & key, Material & currMtrl);
    
    static bool processTransfo(std::ifstream & inf, const std::string & key, TransfoStack & stack);

	static Shape * createShape(std::ifstream & inf, const std::string & key, const Material & currMtrl, const Transfo & currTransfo);
    

public:

	static Scene createScene(const std::string & filename);

};

#endif /* SCENEFACTORY_H_ */
