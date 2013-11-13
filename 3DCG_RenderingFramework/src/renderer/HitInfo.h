#ifndef HITINFO_H_
#define HITINFO_H_

#include "Point.h"
#include "Vector.h"
#include "Material.h"
#include <cfloat>

class HitInfo {

	double t;
	Point hitPoint;
	Vector hitNormal;
	Material hitMaterial;

	void copy(const HitInfo & hitInfo);

public:

	HitInfo(double t=DBL_MAX):t(t){}

	HitInfo(double t, const Point & p, const Vector & n, const Material & m):t(t), hitPoint(p), hitNormal(n), hitMaterial(m) { }

	HitInfo(const HitInfo & hitInfo);

	HitInfo& operator=(const HitInfo & hitInfo);

	double getT() const { return t; }

	void setT(double t) { this->t = t; }

	const Point& getHitPoint() const { return hitPoint; }

	void setHitPoint(const Point& hitPoint) { this->hitPoint = hitPoint; }

	const Vector& getHitNormal() const { return hitNormal; }

	void setHitNormal(const Vector& hitNormal) { this->hitNormal = hitNormal; }

	const Material& getHitMaterial() const { return hitMaterial; }

	void setHitMaterial(const Material& hitMaterial) { this->hitMaterial = hitMaterial; }

};

#endif /* HITINFO_H_ */
