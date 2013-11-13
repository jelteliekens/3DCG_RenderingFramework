//
//  RotateTransfo.cpp
//  3DCG_RenderingFramework
//
//  Created by Jelte Liekens on 6/11/13.
//  Copyright (c) 2013 Jelte Liekens. All rights reserved.
//

#include "RotateTransfo.h"
#include <cmath>

RotateTransfo::RotateTransfo(double angle, double rx, double ry, double rz) {
    Vector ra(rx, ry, rz);
    ra.normalize();
    
    double rad = angle * (M_PI / 180);
    
    mat.m[0][0] = cos(rad) + pow(ra.x, 2) * (1 - cos(rad));
    mat.m[0][1] = ra.x * ra.y * (1 - cos(rad)) - ra.z * sin(rad);
    mat.m[0][2] = ra.x * ra.z * (1 - cos(rad)) + ra.y * sin(rad);
    mat.m[1][0] = ra.x * ra.y * (1 - cos(rad)) + ra.z * sin(rad);
    mat.m[1][1] = cos(rad) + pow(ra.y, 2) * (1 - cos(rad));
    mat.m[1][2] = ra.y * ra.z * (1 - cos(rad)) - ra.x * sin(rad);
    mat.m[2][0] = ra.x * ra.z * (1 - cos(rad)) - ra.y * sin(rad);
    mat.m[2][1] = ra.y * ra.z * (1 - cos(rad)) + ra.x * sin(rad);
    mat.m[2][2] = cos(rad) + pow(ra.z, 2) * (1 - cos(rad));
    
    invMat.m[0][0] = cos(rad) + pow(ra.x, 2) * (1 - cos(rad));
    invMat.m[0][1] = ra.x * ra.y * (1 - cos(rad)) + ra.z * sin(rad);
    invMat.m[0][2] = ra.x * ra.z * (1 - cos(rad)) - ra.y * sin(rad);
    invMat.m[1][0] = ra.x * ra.y * (1 - cos(rad)) - ra.z * sin(rad);
    invMat.m[1][1] = cos(rad) + pow(ra.y, 2) * (1 - cos(rad));
    invMat.m[1][2] = ra.y * ra.z * (1 - cos(rad)) + ra.x * sin(rad);
    invMat.m[2][0] = ra.x * ra.z * (1 - cos(rad)) + ra.y * sin(rad);
    invMat.m[2][1] = ra.y * ra.z * (1 - cos(rad)) - ra.x * sin(rad);
    invMat.m[2][2] = cos(rad) + pow(ra.z, 2) * (1 - cos(rad));
}