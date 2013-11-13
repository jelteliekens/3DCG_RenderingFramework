#include "RayTracer.h"
#include "Light.h"
#include <vector>
#include <cmath>
#include <iostream> 

Colour RayTracer::shadeHit(const Ray & ray, const HitInfo & hitInfo) {

	double r = 0;
	double g = 0;
	double b = 0;

	Vector m = hitInfo.getHitNormal();
	Colour drc = hitInfo.getHitMaterial().getDiffuse();
	Colour arc = hitInfo.getHitMaterial().getAmbient();
	Vector p = Vector(hitInfo.getHitPoint());
    
	std::vector<Light*> lights = scene.getLights();
	std::vector<Light*>::const_iterator it;
	it = lights.begin();

	while (it != lights.end()) {
		Light *li = *it;
		Vector s = li->getPosition() + (-1 * p);

		r += calcComponent(li->getColour().r, drc.r, arc.r, s, m);
		g += calcComponent(li->getColour().g, drc.g, arc.g, s, m);
		b += calcComponent(li->getColour().b, drc.b, arc.b, s, m);

		it++;
	}

	return Colour(r, g, b);
}

double RayTracer::calcComponent(double light, double drc, double arc,
		Vector & s, Vector & m) {

	double component;

	if (s.dot(m) > 0) {
		component = (light * drc * s.dot(m))
				/ (sqrt(s.x * s.x + s.y * s.y + s.z * s.z)
						* sqrt(m.x * m.x + m.y * m.y + m.z * m.z))
				+ arc * light;
	} else {
		component = arc * light;
	}

	return component;
}

