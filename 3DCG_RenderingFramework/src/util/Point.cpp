#include "Point.h"
#include <ostream>

void Point::set(double x, double y, double z){
	this->x = x;
	this->y = y;
	this->z = z;
}


std::ostream& operator<<(std::ostream & out, const Point& point) {
    out << "(" << point.x << "," << point.y << "," << point.z << ")";
    return out;
}