#include "DrawableObject.h"

DrawableObject::DrawableObject(Model* model, Shader* shader)
{
	this->model = model;
	this->shader = shader;
}

void DrawableObject::setAndDraw()
{
	glUseProgram(this->shader->getShaderProgram());
	glBindVertexArray(this->model->getVAO());
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

DrawableObject::~DrawableObject()
{
}
