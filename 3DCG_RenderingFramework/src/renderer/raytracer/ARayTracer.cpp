#include "ARayTracer.h"
#include "IRaytraceable.h"
#include "HitInfo.h"
#include <cfloat>
#include <cmath>

using namespace std;

Colour ARayTracer::shade(const Ray & ray){
	HitInfo bestHitInfo(DBL_MAX);
	std::vector<IRaytraceable*> objects = scene.getObjects();
	for(std::vector<IRaytraceable*>::iterator it = objects.begin(); it != objects.end(); ++it) {
	    HitInfo hitInfo = (*it)->intersection(ray);
	    if(hitInfo.getT() < bestHitInfo.getT()){
	       bestHitInfo = hitInfo;
	    }
	}
	return (bestHitInfo.getT() == DBL_MAX) ? scene.getBackground() : shadeHit(ray, bestHitInfo);
}


Colour ARayTracer::addDiffuse(const Light & light, const Colour &drc, const Vector & s, const Vector & m) {
    double r,g,b;
    r = g = b = 0;
    
    Colour colour;
    
    if (s.dot(m) > 0) {
		colour = (light.getColour() * drc) * (s.dot(m) / (s.length() * m.length()));
    }
    
    return colour;
}

Colour ARayTracer::addAmbient(const Light & light, const Colour & arc) {
    Colour c = arc * light.getColour();
    return c;
}