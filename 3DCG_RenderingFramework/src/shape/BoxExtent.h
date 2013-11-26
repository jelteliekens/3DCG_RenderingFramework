//
//  BoxExtent.h
//  3DCG_RenderingFramework
//
//  Created by Jelte Liekens on 19/11/13.
//  Copyright (c) 2013 Jelte Liekens. All rights reserved.
//

#ifndef ___DCG_RenderingFramework__BoxExtent__
#define ___DCG_RenderingFramework__BoxExtent__

#include <iostream>
#include "Ray.h"

class BoxExtent {
private:
    double left, top, right, bottom, front, back;

public:
    BoxExtent(double left, double right, double top, double bottom, double front, double back):left(left), top(top), right(right), bottom(bottom), front(front), back(back) {}
    BoxExtent():BoxExtent(0,0,0,0,0,0) {}
    
    bool hit(const Ray & ray) const;
};

#endif /* defined(___DCG_RenderingFramework__BoxExtent__) */
