#ifndef SCENE_H_
#define SCENE_H_

#include "IRaytraceable.h"
#include "Light.h"
#include <vector>

class Scene {

	Colour background;
	std::vector<IRaytraceable*> objects;
	std::vector<Light*> lights;

public:

	Scene(){ }

	~Scene();

	const Colour& getBackground() const { return background; }

	void setBackground(const Colour& background) { this->background = background; }

	const std::vector<IRaytraceable*>& getObjects() const { return objects; }

	void addObject(IRaytraceable* object) { objects.push_back(object); }

	const std::vector<Light*>& getLights() const { return lights; }

	void addLight(Light* light) { lights.push_back(light); }

};

#endif /* SCENE_H_ */

