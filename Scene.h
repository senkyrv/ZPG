#pragma once
#include "DrawableObject.h"
#include "Aplication.h"
#include <vector>

class Aplication;
class Scene {
private:
	std::vector<DrawableObject*> drawableObjects;
	int textureId = 0;



public:
	bool clickActionAllowed = false;
	void insertToScene(DrawableObject* o);
	void removeFromScene(int objectId);
	void insertTreeToScene(glm::vec3 position);
	void draw();
	int getAndIncTextureId();
	std::vector<DrawableObject*> getDrawableObjects();
	Scene();
	~Scene();
};