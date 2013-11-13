#include "HitInfo.h"

void HitInfo::copy(const HitInfo & hitInfo){
	t = hitInfo.t;
	hitPoint = Point(hitInfo.hitPoint);
	hitNormal = Vector(hitInfo.hitNormal);
	hitMaterial = Material(hitInfo.hitMaterial);
}

HitInfo::HitInfo(const HitInfo & hitInfo){
	copy(hitInfo);
}

HitInfo& HitInfo::operator=(const HitInfo & hitInfo){
	if(this == &hitInfo){
		return *this;
	}
	copy(hitInfo);
	return *this;
}






