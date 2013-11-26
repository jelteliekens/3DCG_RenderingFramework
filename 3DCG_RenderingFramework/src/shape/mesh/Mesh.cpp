#include "Mesh.h"
#include "IFace.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "Vector.h"
#include "FlatFace.h"
#include "SmoothFace.h"
#include "IFace.h"

Mesh::Mesh(const std::string & filename){
	readFile(filename);
    makeGenBoxExtent();
}

void Mesh::readFile(const std::string & filename){
	std::ifstream inf(filename.c_str());
	if (!inf) {
		std::cout << "Mesh file " << filename << " could not be opened!\n";
		exit(1);
	}
    
    int vertices, nrml, fcs;
    inf >> vertices >> nrml >> fcs;
    
    for (int i = 0; i < vertices; i++) {
        double x, y, z;
        inf >> x >> y >> z;
        
        verts.push_back(Point(x, y, z));
    }
    
    for (int i = 0; i < nrml; i++) {
        double x, y, z;
        inf >> x >> y >> z;
        
        norms.push_back(Vector(x, y, z));
    }
    
    for (int i = 0; i < fcs; i++) {
        IFace * face;
        
        int a;
        inf >> a;
                
        double p1, p2, p3, n1, n2, n3;
        inf >> p1 >> p2 >> p3 >> n1 >> n2 >> n3;
        
        if (n1 == n2 && n2 == n3) {
            face = new FlatFace(&verts[p1], &verts[p2], &verts[p3], norms[n1]);
        } else {
            face = new SmoothFace(&verts[p1], &verts[p2], &verts[p3], &norms[n1], &norms[n2], &norms[n3]);
        }
        
        faces.push_back(face);
    }
}


HitInfo Mesh::intersection(const Ray & ray){
    HitInfo bestHitInfo(DBL_MAX);

    Ray invRay = ray.getInvTransfoRay(getTransfo().getInvMat());
    
    if (genBoxExtent.hit(invRay)) {
    
        for(std::vector<IFace*>::iterator it = faces.begin(); it != faces.end(); ++it) {
            HitInfo hitInfo = (*it)->intersection(invRay);
            if(hitInfo.getT() < bestHitInfo.getT()){
                bestHitInfo = hitInfo;
            }
        }
    
        bestHitInfo.setHitMaterial(Material(mtrl));
        bestHitInfo.setHitNormal(transformHitNormal(bestHitInfo.getHitNormal()));
        bestHitInfo.setHitPoint(ray.getPoint(bestHitInfo.getT()));
    }
    
	return bestHitInfo;
}

void Mesh::makeGenBoxExtent() {
    double left, top, right, bottom, front, back;
    
    left = right = verts[0].x;
    top = bottom = verts[0].y;
    front = back = verts[0].z;

    for (std::vector<Point>::const_iterator it = verts.begin(); it!= verts.end(); it++) {
        Point p = *it;
        if (p.x < left) left = p.x;
        if (p.x > right) right = p.x;
        if (p.y < bottom) bottom = p.y;
        if (p.y > top) top = p.y;
        if (p.z < back) back = p.z;
        if (p.z > front) front = p.z;
    }
    
    //std::cout << left << " " << right  << " " << top  << " " << bottom  << " " << front  << " " << back << std::endl;
    
    genBoxExtent = BoxExtent(left, right, top, bottom, front, back);
}
