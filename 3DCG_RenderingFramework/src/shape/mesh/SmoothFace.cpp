//
//  SmoothFace.cpp
//  3DCG_RenderingFramework
//
//  Created by Jelte Liekens on 5/11/13.
//  Copyright (c) 2013 Jelte Liekens. All rights reserved.
//

#include "SmoothFace.h"
#include <iostream>
#include <cmath>

SmoothFace::SmoothFace(Point* p0, Point* p1, Point* p2, Vector* v0, Vector* v1, Vector* v2) {
    
    verts.push_back(p0);
    verts.push_back(p1);
    verts.push_back(p2);
    
    norms.push_back(v0);
    norms.push_back(v1);
    norms.push_back(v2);
    
    facePlaneNormal = Vector(*p0, *p1).cross(Vector(*p0, *p2));
}

const Point & SmoothFace::getVertex(unsigned int i) const {
    return (* verts[i]);
}

const Vector & SmoothFace::getNormal(unsigned int i) const {
    return (* norms[i]);
}

const Vector & SmoothFace::getFacePlaneNormal() const {
    return facePlaneNormal;
}

Vector SmoothFace::getHitNormal(const Point & hitPoint) {
    Point *p0, *p1, *p2;
    
    p0 = verts[0];
    p1 = verts[1];
    p2 = verts[2];
    
    
    double denom = facePlaneNormal.length();
    double u = Vector(*p0, hitPoint).cross(Vector(*p0, *p2)).length() / denom;
    double v = Vector(*p0, *p1).cross(Vector(*p0, hitPoint)).length() / denom;
    double w = 1 - u - v;
    
    Vector m = w*(*norms[0]) + u*(*norms[1]) + v*(*norms[2]);
    m.normalize();
    
    return m;
}
