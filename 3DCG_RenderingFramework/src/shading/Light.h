#ifndef LIGHT_H_
#define LIGHT_H_

#import "Colour.h"
#import "Point.h"


class Light {

private:

	Point pos;
	Colour colour;

public:

	Light(Point & pos, Colour & colour): pos(pos), colour(colour) {}

	const Point & getPosition() const { return this->pos; }
	const Colour & getColour() const { return this->colour; }

	void setPosition(const Point & point) { this->pos = pos; }
	void setColour(const Colour & colour) { this->colour = colour; }


};

#endif /* LIGHT_H_ */
