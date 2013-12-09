#ifndef SHAPE_H_
#define SHAPE_H_

#include "IRaytraceable.h"
#include "Material.h"
#include "Transfo.h"

class Shape: public IRaytraceable {

protected:

	Material mtrl;
    Transfo transfo;
    
public:

	Shape(){}

	const Material& getMaterial() const { return mtrl; }

	void setMaterial(const Material& mtrl) { this->mtrl = mtrl; }
    
    const Transfo& getTransfo() const { return transfo; }
    
    void setTransfo(const Transfo & transfo) { this->transfo = transfo; }
    
protected:
    
    Vector transformHitNormal(const Vector & hitNormal) {
        Vector t = getTransfo().getInvMat().getTranspose() * hitNormal;
        t.normalize();
        return t;
    }
    
};

#endif /* SHAPE_H_ */
