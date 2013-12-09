#ifndef MESH_H_
#define MESH_H_

#include <string>
#include <vector>
#include "Vector.h"

#include "Shape.h"
#include "IFace.h"
#include "BoxExtent.h"


class Mesh: public Shape {

	std::vector<Point> verts;
	std::vector<Vector> norms;
	std::vector<IFace*> faces;
    BoxExtent genBoxExtent;

public:
	Mesh(const std::string & filename);
	virtual HitInfo intersection(const Ray & ray);
    virtual bool hit(const Ray & ray);

private:
	void readFile(const std::string & filename);
    void makeGenBoxExtent();
};

#endif /* MESH_H_ */
