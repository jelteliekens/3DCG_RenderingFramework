//
//  RayTracerFactory.h
//  3DCG_RenderingFramework
//
//  Created by Jelte Liekens on 26/11/13.
//  Copyright (c) 2013 Jelte Liekens. All rights reserved.
//

#ifndef ___DCG_RenderingFramework__RayTracerFactory__
#define ___DCG_RenderingFramework__RayTracerFactory__

#include <iostream>
#include "ARayTracer.h"
#include "Scene.h"
#include "AppConfigurationFileReader.h"

class RayTracerFactory
{
public:
    static ARayTracer* createRayTracer(const Scene & scene, AppConfiguration & appCfg);
};

#endif /* defined(___DCG_RenderingFramework__RayTracerFactory__) */
