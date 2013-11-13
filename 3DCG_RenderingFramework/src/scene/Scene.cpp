#include "Scene.h"

Scene::~Scene(){
	for(unsigned int i=0; i<objects.size(); ++i){
		delete objects[i];
	}
}
