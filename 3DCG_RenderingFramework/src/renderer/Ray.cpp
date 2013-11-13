//
//  Ray.cpp
//  3DCG_RenderingFramework
//
//  Created by Jelte Liekens on 6/11/13.
//  Copyright (c) 2013 Jelte Liekens. All rights reserved.
//

#include "Ray.h"

Ray Ray::getInvTransfoRay(const Matrix & invMat) const {
    Point invStart = invMat * start;
    Vector invDir = invMat * dir;
    
    return Ray(invStart, invDir);
}