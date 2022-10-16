#include "Transformation.h"


void Transformation::translate(glm::vec3 delta) {
	transformationMatrix *= glm::translate(glm::mat4(1.0f), delta);
}

void Transformation::scale(float scale) {
	transformationMatrix *= glm::scale(glm::mat4(1.0f), glm::vec3(scale));
}

void Transformation::rotate(float angel) {
	transformationMatrix *= glm::rotate(glm::mat4(1.0f), angel, glm::vec3(0.0f, 1.0f, 0.0f));
}

void  Transformation::passTransformationMatrix(Shader* shader)
{
	GLint idModelTransform = glGetUniformLocation(shader->getShaderProgram(), "modelMatrix");
	if (idModelTransform == -1) {
		fprintf(stderr, "Model matrix not found \n");
	}
	glUniformMatrix4fv(idModelTransform, 1, GL_FALSE, &transformationMatrix[0][0]);
}

Transformation::Transformation()
{
}

Transformation::~Transformation()
{
}
