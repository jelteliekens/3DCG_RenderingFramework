//
//  ScaleTransfo.h
//  3DCG_RenderingFramework
//
//  Created by Jelte Liekens on 6/11/13.
//  Copyright (c) 2013 Jelte Liekens. All rights reserved.
//

#ifndef ___DCG_RenderingFramework__ScaleTransfo__
#define ___DCG_RenderingFramework__ScaleTransfo__

#include <iostream>
#include "Transfo.h"

class ScaleTransfo: public Transfo {
public:
    ScaleTransfo(double sx, double sy, double sz);
};

#endif /* defined(___DCG_RenderingFramework__ScaleTransfo__) */
