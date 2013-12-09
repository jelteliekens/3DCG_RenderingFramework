#include "Colour.h"
#include <iostream>

Colour operator*(const Colour & c1, const Colour & c2){
	return Colour(c1.r*c2.r, c1.g*c2.g, c1.b*c2.b);
}

Colour operator*(const Colour & c, double a) {
	return Colour(c.r * a, c.g * a, c.b * a);
}

Colour operator*(double a, const Colour & c) {
	return c * a;
}

void Colour::operator+=(const Colour & c){
	r+=c.r;
	g+=c.g;
	b+=c.b;
}

std::ostream& operator<<(std::ostream & out, const Colour& colour) {
    out << "(" << colour.r << "," << colour.g << "," << colour.b << ")";
    return out;
}