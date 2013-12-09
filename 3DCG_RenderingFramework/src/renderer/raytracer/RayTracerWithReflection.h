//
//  RayTracerWithReflection.h
//  3DCG_RenderingFramework
//
//  Created by Jelte Liekens on 28/11/13.
//  Copyright (c) 2013 Jelte Liekens. All rights reserved.
//

#ifndef ___DCG_RenderingFramework__RayTracerWithReflection__
#define ___DCG_RenderingFramework__RayTracerWithReflection__

#include <iostream>
#include "ARayTracer.h"
#include "AppConfigurationFileReader.h"

class RayTracerWithReflection: public ARayTracer {

    bool isInShadow(const Ray & ray);
    int maxRecursionDepth;
    
    Ray computeReflectedRay(const Ray & ray, const HitInfo & hitInfo);
    
public:
    
	RayTracerWithReflection(const Scene & scene, AppConfiguration & appCfg);
    
	virtual ~RayTracerWithReflection(){ }
    
protected:
    
	virtual Colour shadeHit(const Ray & ray, const HitInfo & hitInfo);
    
};

#endif /* defined(___DCG_RenderingFramework__RayTracerWithReflection__) */
