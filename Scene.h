#pragma once

#include <vector>


#include "Shader.h"
#include "CallbackController.h"
#include "CallbackController.h"
class Camera;
class Scene {
private:
	// std::vector<Object> objects;
	Camera* camera;

public:
	Scene();
	~Scene();
	void render();
	void updateCamera();
};