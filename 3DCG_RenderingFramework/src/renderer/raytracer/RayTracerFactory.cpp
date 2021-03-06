//
//  RayTracerFactory.cpp
//  3DCG_RenderingFramework
//
//  Created by Jelte Liekens on 26/11/13.
//  Copyright (c) 2013 Jelte Liekens. All rights reserved.
//

#include "RayTracerFactory.h"
#include "RayTracer.h"
#include "RayTracerWithShadow.h"
#include "RayTracerWithReflection.h"

ARayTracer* RayTracerFactory::createRayTracer(const Scene & scene,  AppConfiguration & appCfg) {
    
    ARayTracer * rayTracer = 0;
    
    std::string mode = appCfg["raytracer.mode"];
    
    if (mode.compare("basic")==0) {
        rayTracer = new RayTracer(scene);
    } else if (mode.compare("shadow")==0) {
        rayTracer = new RayTracerWithShadow(scene);
    } else if (mode.compare("reflection")==0) {
        rayTracer = new RayTracerWithReflection(scene, appCfg);
    } else {
        rayTracer = new RayTracer(scene);
    }


    return rayTracer;
}
