#pragma once
#include "DrawableObject.h"
#include <vector>

class Scene {
private:
	std::vector<DrawableObject*> drawableObjects;

public:
	void insertToScene(DrawableObject* o);
	void draw();
	Scene();
	~Scene();
};