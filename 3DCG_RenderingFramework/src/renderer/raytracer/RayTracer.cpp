#include "RayTracer.h"
#include "Light.h"
#include "Colour.h"
#include <vector>
#include <iostream>
#include <cmath>

Colour RayTracer::shadeHit(const Ray & ray, const HitInfo & hitInfo) {
    Colour colour;
    
    Vector m = hitInfo.getHitNormal();
    Colour drc = hitInfo.getHitMaterial().getDiffuse();
    Colour arc = hitInfo.getHitMaterial().getAmbient();
    Point p = hitInfo.getHitPoint();
    
    std::vector<Light*> lights = scene.getLights();
    
	for(std::vector<Light*>::iterator it = lights.begin(); it != lights.end(); ++it) {
        Light *li = *it;
        Vector s = Vector(p, li->getPosition());
        
        colour += addDiffuse(*li, drc, s, m);
        colour += addAmbient(*li, arc);
    }
    
    return colour;
}

