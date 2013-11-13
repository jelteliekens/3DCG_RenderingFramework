//
//  ScaleTransfo.cpp
//  3DCG_RenderingFramework
//
//  Created by Jelte Liekens on 6/11/13.
//  Copyright (c) 2013 Jelte Liekens. All rights reserved.
//

#include "ScaleTransfo.h"

ScaleTransfo::ScaleTransfo(double sx, double sy, double sz) {
    
    mat.m[0][0] = sx;
    mat.m[1][1] = sy;
    mat.m[2][2] = sz;


    invMat.m[0][0] = 1/sx;
    invMat.m[1][1] = 1/sy;
    invMat.m[2][2] = 1/sz;
}
