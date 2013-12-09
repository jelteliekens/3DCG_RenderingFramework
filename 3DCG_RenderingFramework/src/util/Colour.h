#ifndef COLOUR_H_
#define COLOUR_H_

#include <iostream>

class Colour {

public:

	double r, g, b;

	Colour(double r = 0, double g = 0, double b = 0): r(r), g(g), b(b){ }

    friend Colour operator*(const Colour & c1, const Colour & c2);
    
    friend Colour operator*(const Colour & c, double a);
    
	friend Colour operator*(double a, const Colour & c);
    
    void operator+=(const Colour & c);
    
    void operator+(const Colour & c);
    
    friend std::ostream& operator<<(std::ostream & out, const Colour& colour);
};

#endif /* COLOUR_H_ */
