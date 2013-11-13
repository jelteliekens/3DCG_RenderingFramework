#include "ARayTracer.h"
#include "IRaytraceable.h"
#include "HitInfo.h"
#include <cfloat>

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


