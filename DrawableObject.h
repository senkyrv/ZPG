#pragma once

#include "Model.h"
#include "Shader.h"
#include "Transformation.h"
#include "AbstractModel.h"
class DrawableObject {

private:
	AbstractModel* model;
	Shader* shader;
	Transformation* transformation;

	//Texture* texture;

public:
	int objectId = 0;
	DrawableObject(AbstractModel* model, Shader* shader, Transformation* transformation);
	//DrawableObject(AbstractModel* model, Shader* shader, Transformation* transformation, Texture* texture);
	void draw();
	Shader* getShader();
	~DrawableObject();
};
