#ifndef RAY_H_
#define RAY_H_

#include "Point.h"
#include "Vector.h"
#include "Matrix.h"

class Ray {

	Point start;
	Vector dir;

public:

	Ray(const Point & start, const Vector & dir=0):start(start), dir(dir){ }

	const Vector& getDir() const { return dir; }

	void setDir(const Vector& dir) { this->dir = dir; }

	const Point& getStart() const { return start; }

	void setStart(const Point& start) { this->start = start; }

	Point getPoint(double t) const { return this->start + t*this->dir; }
    
    Ray getInvTransfoRay(const Matrix & invMat) const;
};

#endif /* RAY_H_ */
