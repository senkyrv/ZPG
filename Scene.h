#pragma once

#include <vector>

#include "CallbackController.h"
#include "DrawableObject.h"
#include "Shader.h"
class Camera;
class Scene {
private:
	std::vector<DrawableObject*> objects;
	// Camera *camera;

public:
	Scene();
	~Scene();
	void render();
	void updateCamera();
	void addObject(DrawableObject* o);
};