#include "Square.h"
#include <cmath>
#include "HitInfo.h"

HitInfo Square::intersection(const Ray & ray){
	Ray invRay = ray.getInvTransfoRay(transfo.getInvMat());
	if(std::abs(invRay.getDir().z)<0.00001){
		return HitInfo();
	}
	double t=-invRay.getStart().z/invRay.getDir().z;
	if(t<=0.0){
		return HitInfo();
	}
	Point hitPoint = invRay.getPoint(t);
	if (hitPoint.x > 1.0 || hitPoint.x < -1.0 || hitPoint.y > 1.0 || hitPoint.y < -1.0){
		return HitInfo();
	}
	Vector normal = transfo.getInvMat().getTranspose()*Vector(0,0,1);
	normal.normalize();
	return HitInfo(t, ray.getPoint(t),normal, mtrl);
}



