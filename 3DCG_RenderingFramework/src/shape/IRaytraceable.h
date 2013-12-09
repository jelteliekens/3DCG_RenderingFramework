#ifndef IRAYTRACEABLE_H_
#define IRAYTRACEABLE_H_

#include "HitInfo.h"
#include "Ray.h"

class IRaytraceable {

public:

	virtual HitInfo intersection(const Ray & ray)=0;
    virtual bool hit(const Ray & ray)=0;
	virtual ~IRaytraceable(){ };
};

#endif /* IRAYTRACEABLE_H_ */
