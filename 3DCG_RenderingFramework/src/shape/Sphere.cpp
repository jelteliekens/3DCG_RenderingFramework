#include "Sphere.h"
#include "Ray.h"
#include <cmath>
#include <iostream>

HitInfo Sphere::intersection(const Ray & ray) {
    Ray invRay = ray.getInvTransfoRay(getTransfo().getInvMat());
    
	Vector dir = invRay.getDir();
	Vector start(invRay.getStart());

	double a = dir.dot(dir);
	double b = 2 * start.dot(dir);
	double c = start.dot(start) - 1;

	double discr = b * b - 4 * a * c;

	if (discr == 0) {

		double t = -b / (2 * a);
		return HitInfo(t, ray.getPoint(t), transformHitNormal(invRay.getPoint(t)),mtrl);

	} else if (discr > 0) {

		double t1 = (-b + sqrt(discr)) / (2 * a);
		double t2 = (-b - sqrt(discr)) / (2 * a);

		if (t2 > 0) {
			return HitInfo(t2, ray.getPoint(t2), transformHitNormal(invRay.getPoint(t2)), mtrl);
		} else {
			if (t1 > 0) {
				return HitInfo(t1, ray.getPoint(t1), transformHitNormal(invRay.getPoint(t1)), mtrl);
			} else {
				return HitInfo();
			}
		}

	} else {
		return HitInfo();
	}
}

bool Sphere::hit(const Ray & ray) {
    Ray invRay = ray.getInvTransfoRay(getTransfo().getInvMat());
    
	Vector dir = invRay.getDir();
	Vector start(invRay.getStart());
        
	double a = dir.dot(dir);
	double b = 2 * start.dot(dir);
	double c = start.dot(start) - 1;
    
	double discr = b * b - 4 * a * c;
    
	if (discr == 0) {

		double t = -b / (2 * a);
		return t > 0 && t < 1;
        
	} else if (discr > 0) {
        
		double t1 = (-b + sqrt(discr)) / (2 * a);
		double t2 = (-b - sqrt(discr)) / (2 * a);
        
		if (t2 > 0 && t2 < 1) {
            return true;
		} else if (t1 > 0 && t1 < 1) {
            return true;
        }
	}
    
    return false;
}