#ifndef ARAYTRACER_H_
#define ARAYTRACER_H_

#include "Scene.h"

class ARayTracer {

protected:

	Scene scene;

	virtual Colour shadeHit(const Ray & ray, const HitInfo & hitInfo) = 0;

public:

	ARayTracer(const Scene & scene): scene(scene){ }

	virtual ~ARayTracer(){ }

	Colour shade(const Ray & ray);

};

#endif /* ARAYTRACER_H_ */
