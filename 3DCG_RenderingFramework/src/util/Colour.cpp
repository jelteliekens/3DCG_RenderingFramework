#include "Colour.h"

Colour operator*(const Colour & c1, const Colour & c2){
	return Colour(c1.r*c2.r, c1.g*c2.g, c1.b*c2.b);
}

void Colour::operator+=(const Colour & c){
	r+=c.r;
	g+=c.g;
	b+=c.b;
}
