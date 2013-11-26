//
//  BoxExtent.cpp
//  3DCG_RenderingFramework
//
//  Created by Jelte Liekens on 19/11/13.
//  Copyright (c) 2013 Jelte Liekens. All rights reserved.
//

#include "BoxExtent.h"
#include "Ray.h"
#include "Point.h"
#include <cmath>

bool BoxExtent::hit(const Ray & ray) const {
    double numer;
    double denom;
    double tHit;
    
    //FRONT FACE
    numer = front - ray.getStart().z;
    denom = ray.getDir().z;
    
    if(std::abs(denom) > 0.0000001) {
        tHit = numer/denom;
        
        if(tHit >= 0) {
            Point hp = ray.getPoint(tHit);
            
            if(hp.x >= left && hp.x <= right && hp.y <= top && hp.y >= bottom){
                return true;
            }
        }
    }
    
    //BACK FACE
    numer = -(back - ray.getStart().z);
    denom = -ray.getDir().z;
    
    if(std::abs(denom) > 0.0000001) {
        tHit = numer/denom;
        
        if(tHit >= 0) {
            Point hp = ray.getPoint(tHit);
            
            if(hp.x >= left && hp.x <= right && hp.y <= top && hp.y >= bottom){
                return true;
            }
        }
    }
    
    //RIGHT FACE
    numer = right - ray.getStart().x;
    denom = ray.getDir().x;
    
    if(std::abs(denom) > 0.0000001) {
        tHit = numer/denom;
        
        if(tHit >= 0) {
            Point hp = ray.getPoint(tHit);
            
            if(hp.z >= back && hp.z <= front && hp.y <= top && hp.y >= bottom){
                return true;
            }
        }
    }
    
    //LEFT FACE
    numer = -(left - ray.getStart().x);
    denom = -ray.getDir().x;
    
    if(std::abs(denom) > 0.0000001) {
        tHit = numer/denom;
        
        if(tHit >= 0) {
            Point hp = ray.getPoint(tHit);
            
            if(hp.z >= back && hp.z <= front && hp.y <= top && hp.y >= bottom){
                return true;
            }
        }
    }
    
    //TOP FACE
    numer = top - ray.getStart().y;
    denom = ray.getDir().y;
    
    if(std::abs(denom) > 0.0000001) {
        tHit = numer/denom;
        
        if(tHit >= 0) {
            Point hp = ray.getPoint(tHit);
            
            if(hp.z >= back && hp.z <= front &&  hp.x >= left && hp.x <= right){
                return true;
            }
        }
    }

    return false;

}