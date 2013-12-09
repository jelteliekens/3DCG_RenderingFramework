#include "Material.h"

Material::Material(){
	diffuse = Colour(1,0,0);
	ambient = Colour(0.2,0,0);
    reflectivity = 0;
}

Material::Material(const Material & mtrl){
	diffuse = Colour(mtrl.getDiffuse());
	ambient = Colour(mtrl.getAmbient());
    reflectivity = mtrl.reflectivity;
}

Material& Material::operator=(const Material & mtrl){
	if(this == &mtrl){
		return *this;
	}
	diffuse = Colour(mtrl.getDiffuse());
	ambient = Colour(mtrl.getAmbient());
    reflectivity = mtrl.getReflectivity();
	return *this;
}
