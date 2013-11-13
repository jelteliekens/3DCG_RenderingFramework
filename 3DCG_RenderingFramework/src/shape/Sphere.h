#ifndef SPHERE_H_
#define SPHERE_H_

#include "Shape.h"

class Sphere: public Shape {
    
public:

	virtual HitInfo intersection(const Ray & ray);

};

#endif /* SPHERE_H_ */
