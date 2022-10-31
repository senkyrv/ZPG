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

public:
	DrawableObject(AbstractModel* model, Shader* shader, Transformation* transformation);
	void draw();
	~DrawableObject();
};
