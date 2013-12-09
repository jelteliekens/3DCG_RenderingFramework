//
//  RayTracerWithShadow.h
//  3DCG_RenderingFramework
//
//  Created by Jelte Liekens on 28/11/13.
//  Copyright (c) 2013 Jelte Liekens. All rights reserved.
//

#ifndef ___DCG_RenderingFramework__RayTracerWithShadow__
#define ___DCG_RenderingFramework__RayTracerWithShadow__

#include <iostream>
#include "ARayTracer.h"

class RayTracerWithShadow: public ARayTracer {
    
    bool isInShadow(const Ray & ray);

public:
    
	RayTracerWithShadow(const Scene & scene):ARayTracer(scene){ }
    
	virtual ~RayTracerWithShadow(){ }
    
protected:
    
	virtual Colour shadeHit(const Ray & ray, const HitInfo & hitInfo);

};

#endif /* defined(___DCG_RenderingFramework__RayTracerWithShadow__) */
