//
//  SmoothFace.h
//  3DCG_RenderingFramework
//
//  Created by Jelte Liekens on 5/11/13.
//  Copyright (c) 2013 Jelte Liekens. All rights reserved.
//

#ifndef ___DCG_RenderingFramework__SmoothFace__
#define ___DCG_RenderingFramework__SmoothFace__

#include "AFace.h"
#include <vector>

class SmoothFace: public AFace {
private:
    
    std::vector<Point *> verts;
    std::vector<Vector *> norms;
    Vector facePlaneNormal;
    
public:
    
    SmoothFace(Point* p0, Point* p1, Point* p2, Vector* v0, Vector* v1, Vector* v2);
    
	virtual const Point & getVertex(unsigned int i) const;
	virtual const Vector & getNormal(unsigned int i) const;
	virtual const Vector & getFacePlaneNormal() const;
    
protected:
	virtual Vector getHitNormal(const Point & hitPoint);
    
};

#endif /* defined(___DCG_RenderingFramework__SmoothFace__) */
