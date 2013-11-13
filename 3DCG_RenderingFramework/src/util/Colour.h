#ifndef COLOUR_H_
#define COLOUR_H_

class Colour {

public:

	double r, g, b;

	Colour(double r = 0, double g = 0, double b = 0): r(r), g(g), b(b){ }

    friend Colour operator*(const Colour & c1, const Colour & c2);

    void operator+=(const Colour & c);
};

#endif /* COLOUR_H_ */
