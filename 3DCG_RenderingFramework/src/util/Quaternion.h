#ifndef QUATERNION_H_
#define QUATERNION_H_

#import "Point.h"
#import "Vector.h"

class Quaternion {
public:
	double a,b,c,d;

	Quaternion(double a, double b, double c, double d): a(a), b(b), c(c), d(d) {}
	Quaternion(Point& point);
	Quaternion(double angle, Vector& r);

	Quaternion operator*(const Quaternion& q);

	Quaternion conjugate();
};

#endif /* QUATERNION_H_ */
