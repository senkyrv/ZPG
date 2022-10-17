#pragma once

#include "Model.h"
#include "Shader.h"
#include "Transformation.h"

class DrawableObject {

private:
	Model* model;
	Shader* shader;
	Transformation* transformation;

public:
	DrawableObject(Model* model, Shader* shader, Transformation* transformation);
	void setAndDraw();
	~DrawableObject();
};
