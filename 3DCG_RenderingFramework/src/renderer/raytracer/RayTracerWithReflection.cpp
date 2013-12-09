//
//  RayTracerWithShadow.cpp
//  3DCG_RenderingFramework
//
//  Created by Jelte Liekens on 28/11/13.
//  Copyright (c) 2013 Jelte Liekens. All rights reserved.
//

#include "RayTracerWithReflection.h"
#include <cmath>
#include <iostream>


RayTracerWithReflection::RayTracerWithReflection(const Scene & scene, AppConfiguration & appCfg):ARayTracer(scene) {
    maxRecursionDepth = std::atof(appCfg["raytracer.reflection.maxRecursionDepth"].c_str());
}

Colour RayTracerWithReflection::shadeHit(const Ray & ray, const HitInfo & hitInfo) {
    
    Colour colour;
    Ray shadowFeeler(hitInfo.getHitPoint() + 0.000001 * hitInfo.getHitNormal());
    
	Vector m = hitInfo.getHitNormal();
	Colour drc = hitInfo.getHitMaterial().getDiffuse();
	Colour arc = hitInfo.getHitMaterial().getAmbient();
    Point p = hitInfo.getHitPoint();
    
	std::vector<Light*> lights = scene.getLights();
    
    for(std::vector<Light*>::iterator it = lights.begin(); it != lights.end(); ++it) {
		Light *li = *it;
        Vector s = Vector(p, li->getPosition());
        
        colour += addAmbient(*li, arc);
        
        Vector shadowFeelerDir(hitInfo.getHitPoint(), li->getPosition());
        shadowFeeler.setDir(shadowFeelerDir);
        
        if (!isInShadow(shadowFeeler)) {
            colour += addDiffuse(*li, drc, s, m);
        }
    }
    
    if(ray.getRecursionDepth() <= maxRecursionDepth && hitInfo.getHitMaterial().getReflectivity() >= 0.1){
        Ray reflRay = computeReflectedRay(ray, hitInfo);
        colour += shade(reflRay) * hitInfo.getHitMaterial().getReflectivity();
    }
    
	return colour;
}

Ray RayTracerWithReflection::computeReflectedRay(const Ray & ray, const HitInfo & hitInfo) {
    Ray reflRay(hitInfo.getHitPoint() + 0.000001 * hitInfo.getHitNormal());
    
    Vector dir = ray.getDir();
    Vector m = hitInfo.getHitNormal();
    double mLength = m.length();
    double dotDirM = dir.dot(m);
    
    Vector sec = (-2 * dotDirM) / (std::pow(mLength, 2)) * m;
    Vector r = dir + sec;
    
    reflRay.setDir(r);
    reflRay.setRecursionDepth(ray.getRecursionDepth() + 1);
    
    return reflRay;
}

bool RayTracerWithReflection::isInShadow(const Ray & ray) {
    
    std::vector<IRaytraceable*> objects = scene.getObjects();
    
    for (std::vector<IRaytraceable*>::const_iterator it = objects.begin(); it != objects.end(); it++) {
        if ((*it)->hit(ray)) return true;
    }
    
    return false;
}