#ifndef RAYTRACER_H_
#define RAYTRACER_H_

#include "ARayTracer.h"
#include "Scene.h"
#include "Colour.h"
#include "Ray.h"
#include "HitInfo.h"

class RayTracer: public ARayTracer {
private:

	double calcComponent(double light, double drc, double arc, Vector & s, Vector & m);

public:

	RayTracer(const Scene & scene):ARayTracer(scene){ }

	virtual ~RayTracer(){ }

	virtual Colour shadeHit(const Ray & ray, const HitInfo & hitInfo);
};

#endif /* RAYTRACER_H_ */
