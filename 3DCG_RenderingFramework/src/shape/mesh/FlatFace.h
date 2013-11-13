#ifndef FLATFACE_H_
#define FLATFACE_H_

#include "AFace.h"
#include <vector>

class FlatFace: public AFace {

	std::vector<Point *> verts;
	Vector normal;

public:
	FlatFace(Point * p0, Point * p1, Point * p2, const Vector & normal);

	virtual const Point & getVertex(unsigned int i) const;
	virtual const Vector & getNormal(unsigned int i) const;
	virtual const Vector & getFacePlaneNormal() const;

protected:
	virtual Vector getHitNormal(const Point & hitPoint);

};

#endif /* FLATFACE_H_ */
