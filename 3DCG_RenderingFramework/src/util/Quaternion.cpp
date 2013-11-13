#import "Quaternion.h"
#import <cmath>

#define PI 3.14159265358979323846

Quaternion::Quaternion(Point& point) {
	a = 0;
	b = point.x;
	c = point.y;
	d = point.z;
}

Quaternion::Quaternion(double angle, Vector& r) {

	double radian = angle * PI / 180;

	a = cos(radian/2);
	b = sin(radian/2)*r.x;
	c = sin(radian/2)*r.y;
	d = sin(radian/2)*r.z;
}

Quaternion Quaternion::operator*(const Quaternion& q) {
	double aa,bb,cc,dd;
	aa = a*q.a - b*q.b - c*q.c - d*q.d;
	bb = a*q.b + b*q.a + c*q.d - d*q.c;
	cc = a*q.c - b*q.d + c*q.a + d*q.b;
	dd = a*q.d + b*q.c - c*q.b + d*q.a;

	return Quaternion(aa,bb,cc,dd);
}


Quaternion Quaternion::conjugate() {
	return Quaternion(a, -b, -c, -d);
}

