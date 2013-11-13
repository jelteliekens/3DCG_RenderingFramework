#include "FlatFace.h"

FlatFace::FlatFace(Point * p0, Point * p1, Point * p2, const Vector & normal):normal(normal){
	verts.push_back(p0);
	verts.push_back(p1);
	verts.push_back(p2);
}

const Point & FlatFace::getVertex(unsigned int i) const{
	return *(verts[i]);
}

const Vector & FlatFace::getNormal(unsigned int i) const{
	return normal;
}

const Vector & FlatFace::getFacePlaneNormal() const{
	return normal;
}

Vector FlatFace::getHitNormal(const Point & hitPoint){
	return normal;
}
