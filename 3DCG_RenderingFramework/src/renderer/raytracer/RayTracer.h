#ifndef RAYTRACER_H_
#define RAYTRACER_H_

#include "ARayTracer.h"
#include "Scene.h"
#include "Colour.h"
#include "Ray.h"
#include "HitInfo.h"

class RayTracer: public ARayTracer {
public:

	RayTracer(const Scene & scene):ARayTracer(scene){ }

	virtual ~RayTracer(){ }
    
protected:

	virtual Colour shadeHit(const Ray & ray, const HitInfo & hitInfo);
};

#endif /* RAYTRACER_H_ */
