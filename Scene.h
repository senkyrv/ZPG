#pragma once

#include <vector>

#include "CallbackController.h"
#include "DrawableObject.h"
#include "Shader.h"

class Scene {
private:

	std::vector<DrawableObject*> drawableObjects;

public:

	Scene();
	~Scene();
	void addObject(DrawableObject* o);
	void render();
};