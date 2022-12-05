#include "DrawableObject.h"

DrawableObject::DrawableObject(AbstractModel* model, Shader* shader, Transformation* transformation)
{

	this->transformation = transformation;
	this->model = model;
	this->shader = shader;
}
//
//DrawableObject::DrawableObject(AbstractModel* model, Shader* shader, Transformation* transformation, Texture* texture)
//{
//
//	this->transformation = transformation;
//	this->model = model;
//	this->shader = shader;
//	this->texture = texture;
//}

void DrawableObject::draw()
{
	//if (shader->isTextured) {
	//	texture->applyTexture(shader->getShaderProgram());
	//}
	model->draw(shader, transformation);
}

Shader* DrawableObject::getShader()
{
	return shader;
}


DrawableObject::~DrawableObject()
{
}
