//
//  RotateTransfo.h
//  3DCG_RenderingFramework
//
//  Created by Jelte Liekens on 6/11/13.
//  Copyright (c) 2013 Jelte Liekens. All rights reserved.
//

#ifndef ___DCG_RenderingFramework__RotateTransfo__
#define ___DCG_RenderingFramework__RotateTransfo__

#include <iostream>
#include "Transfo.h"

class RotateTransfo: public Transfo {
public:
    RotateTransfo(double angle, double rx, double ry, double rz);
};

#endif /* defined(___DCG_RenderingFramework__RotateTransfo__) */
