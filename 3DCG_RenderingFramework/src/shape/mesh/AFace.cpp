#include "AFace.h"
#include <cmath>
#include <iostream>

HitInfo AFace::intersection(const Ray & invRay){
    
	Point point = getVertex(0);
	Vector m = getFacePlaneNormal();

	if (abs(m.dot(invRay.getDir())) < 0.0000001) {
        
		return HitInfo();

	} else {

		double thit = m.dot(Vector(invRay.getStart(), point)) / m.dot(invRay.getDir());

		if (thit < 0) {
			return HitInfo();
		} else {

			bool ok = true;

			for (int i = 0; i < 3 && ok; i++) {
				Vector v1(getVertex(i%3), getVertex((i+1)%3));
				Vector v2(getVertex(i%3), invRay.getPoint(thit));
				Vector v3 = v1.cross(v2);
                
				ok = v3.dot(m) > 0;
            }

			if (ok) {
				return HitInfo(thit, invRay.getPoint(thit), getHitNormal(invRay.getPoint(thit)), Material());
			} else {
				return HitInfo();
			}
		}

	}

}
