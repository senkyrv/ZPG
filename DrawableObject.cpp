#include "DrawableObject.h"

DrawableObject::DrawableObject(Model* model, Shader* shader, Transformation* transformation)
{
	this->model = model;
	this->shader = shader;
	this->transformation = transformation;
}

void DrawableObject::setAndDraw()
{
	glUseProgram(this->shader->getShaderProgram());
	glBindVertexArray(this->model->getVAO());
	glDrawArrays(GL_TRIANGLES, 0, 3);  // mode,first,count
	GLint idModelTransform =
		glGetUniformLocation(shader->getShaderProgram(), "modelMatrix");
	if (idModelTransform == -1) {
		fprintf(stderr, "matrixModel not found \n");
	}
	glUniformMatrix4fv(idModelTransform, 1, GL_FALSE,
		&transformation->getMatrix()[0][0]);
}

DrawableObject::~DrawableObject()
{
}
