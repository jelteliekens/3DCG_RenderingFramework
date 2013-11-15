#include "Sphere.h"
#include "Ray.h"
#include <cmath>

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
		return HitInfo(t, ray.getPoint(t), ray.getPoint(t),mtrl);

	} else if (discr > 0) {

		double t1 = (-b + sqrt(discr)) / (2 * a);
		double t2 = (-b - sqrt(discr)) / (2 * a);

		if (t2 > 0) {

			return HitInfo(t2, ray.getPoint(t2), ray.getPoint(t2), mtrl);
		} else {
			if (t1 > 0) {
				return HitInfo(t1, ray.getPoint(t1), ray.getPoint(t1), mtrl);
			} else {
				return HitInfo();
			}
		}

	} else {
		return HitInfo();
	}
}