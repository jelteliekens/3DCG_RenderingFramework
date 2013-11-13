#ifndef POINT_H_
#define POINT_H_

#include <ostream>

class Point {

public:

	double x;
	double y;
	double z;

	Point(double x=0, double y=0, double z=0): x(x), y(y), z(z){ }

	void set(double x, double y, double z);
    
    friend std::ostream& operator<<(std::ostream & out, const Point& point);

};

#endif /* POINT_H_ */
