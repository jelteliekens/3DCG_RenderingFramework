#ifndef AFACE_H_
#define AFACE_H_

#include "IFace.h"

class AFace: public IFace {

public:
	virtual HitInfo intersection(const Ray & ray);
	virtual ~AFace(){ };
protected:
	virtual Vector getHitNormal(const Point & hitPoint) = 0;
};

#endif /* AFACE_H_ */
