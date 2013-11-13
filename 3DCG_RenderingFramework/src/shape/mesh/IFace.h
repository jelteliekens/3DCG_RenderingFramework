#ifndef IFACE_H_
#define IFACE_H_

#include "IRaytraceable.h"
#include "Point.h"
#include "Vector.h"

class IFace: public IRaytraceable {

public:
	virtual const Point & getVertex(unsigned int i) const = 0;
	virtual const Vector & getNormal(unsigned int i) const = 0;
	virtual const Vector & getFacePlaneNormal() const = 0;

	virtual ~IFace(){ };
};

#endif /* IFACE_H_ */
