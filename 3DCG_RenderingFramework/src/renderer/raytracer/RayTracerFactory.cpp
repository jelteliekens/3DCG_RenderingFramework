//
//  RayTracerFactory.cpp
//  3DCG_RenderingFramework
//
//  Created by Jelte Liekens on 26/11/13.
//  Copyright (c) 2013 Jelte Liekens. All rights reserved.
//

#include "RayTracerFactory.h"
#include "RayTracer.h"

ARayTracer* RayTracerFactory::createRayTracer(const Scene & scene,  AppConfiguration & appCfg) {
    
    ARayTracer * rayTracer;
    
    std::string mode = appCfg["raytracer.mode"];
    std::cout << mode;
    
    if (mode.compare("basic")==0) {
        rayTracer = new RayTracer(scene);
    } else {
        rayTracer = new RayTracer(scene);
    }

    return rayTracer;
}
