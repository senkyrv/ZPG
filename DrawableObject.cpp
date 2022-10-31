#include "DrawableObject.h"

DrawableObject::DrawableObject(AbstractModel* model, Shader* shader, Transformation* transformation)
{

	this->transformation = transformation;
	this->model = model;
	this->shader = shader;
}

void DrawableObject::draw()
{
	model->draw(shader, transformation);
}

DrawableObject::~DrawableObject()
{
}
