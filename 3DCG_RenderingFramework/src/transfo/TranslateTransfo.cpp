//
//  TranslateTransfo.cpp
//  3DCG_RenderingFramework
//
//  Created by Jelte Liekens on 6/11/13.
//  Copyright (c) 2013 Jelte Liekens. All rights reserved.
//

#include "TranslateTransfo.h"

TranslateTransfo::TranslateTransfo(double tx, double ty, double tz) {
    mat.m[0][3] = tx;
    mat.m[1][3] = ty;
    mat.m[2][3] = tz;

    invMat.m[0][3] = -tx;
    invMat.m[1][3] = -ty;
    invMat.m[2][3] = -tz;
}
