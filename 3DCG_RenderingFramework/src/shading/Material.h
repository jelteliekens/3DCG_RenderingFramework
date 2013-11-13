#ifndef MATERIAL_H_
#define MATERIAL_H_

#include "Colour.h"

class Material {

	Colour diffuse;
	Colour ambient;

public:

	Material();

	Material(const Material & mtrl);

	Material& operator=(const Material & mtrl);

	const Colour & getDiffuse() const { return diffuse; }

	void setDiffuse(const Colour & diffuse) { this->diffuse = diffuse; }

	const Colour & getAmbient() const { return ambient; }

	void setAmbient(const Colour & ambient) { this->ambient = ambient; }

};

#endif /* MATERIAL_H_ */
