#include "Vector.h"
#include <cmath>
#include <ostream>

Vector::Vector(const Point & from, const Point & to) {
	x = to.x - from.x;
	y = to.y - from.y;
	z = to.z - from.z;
}

Vector operator*(const Vector & v, double a) {
	return Vector(v.x * a, v.y * a, v.z * a);
}

Vector operator*(double a, const Vector & v) {
	return v * a;
}

Point operator+(const Point & p, const Vector & v) {
	return Point(p.x + v.x, p.y + v.y, p.z + v.z);
}

Point operator+(const Vector & v, const Point & p) {
	return p + v;
}

Vector operator+(const Vector & v1, const Vector & v2) {
	return Vector(v1.x +  v2.x, v1.y + v2.y, v1.z + v2.z);
}

double Vector::dot(const Vector & v) const {
	return (x * v.x) + (y * v.y) + (z * v.z);
}

Vector Vector::cross(const Vector & v) const {
	return Vector((y * v.z - z * v.y), (z * v.x - x * v.z), (x * v.y - y * v.x));
}

void Vector::normalize() {
	double length = std::sqrt(x*x + y*y + z*z);
	x = x / length;
	y = y / length;
	z = z / length;
}

double Vector::length() const {
    return std::sqrt(x*x + y*y + z*z);
}

std::ostream& operator<<(std::ostream & out, const Vector& vector) {
    out << "(" << vector.x << "," << vector.y << "," << vector.z << ")";
    return out;
}

