#ifndef MATERIAL_H_
#define MATERIAL_H_

#include "Colour.h"
#include <iostream>

class Material {

	Colour diffuse;
	Colour ambient;
    double reflectivity;

public:

	Material();

	Material(const Material & mtrl);

	Material& operator=(const Material & mtrl);

	const Colour & getDiffuse() const { return diffuse; }

	void setDiffuse(const Colour & diffuse) { this->diffuse = diffuse; }

	const Colour & getAmbient() const { return ambient; }

	void setAmbient(const Colour & ambient) { this->ambient = ambient; }
    
    const double getReflectivity() const { return reflectivity; }
    
    void setReflectivity(double reflectivity) { this->reflectivity = reflectivity; }
};

#endif /* MATERIAL_H_ */
