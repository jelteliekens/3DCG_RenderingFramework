#include "AFace.h"
#include <cmath>
#include <iostream>

HitInfo AFace::intersection(const Ray & ray){
    
	Point point = getVertex(0);
	Vector m = getFacePlaneNormal();
    
	if (std::abs(m.dot(ray.getDir())) < 0.0000001) {
        
		return HitInfo();
        
	} else {
        
		double thit = m.dot(Vector(ray.getStart(), point)) / m.dot(ray.getDir());
        
		if (thit < 0) {
			return HitInfo();
		} else {
            
			bool ok = true;
            
			for (int i = 0; i < 3 && ok; i++) {
				Vector v1(getVertex(i%3), getVertex((i+1)%3));
				Vector v2(getVertex(i%3), ray.getPoint(thit));
				Vector v3 = v1.cross(v2);
                
				ok = v3.dot(m) > 0;
            }
            
			if (ok) {
				return HitInfo(thit, ray.getPoint(thit), getHitNormal(ray.getPoint(thit)), Material());
			} else {
				return HitInfo();
			}
		}
        
	}
    
}