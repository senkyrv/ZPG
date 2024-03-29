#include "Transformation.h"

Transformation::Transformation()
{
	this->transformationMatrix = glm::mat4(1.0f);
}

Transformation::~Transformation(){}

void Transformation::rotate(float angel) {
	transformationMatrix *= glm::rotate(glm::mat4(1.0f), angel, glm::vec3(0.0f, 1.0f, 0.0f));
}

void Transformation::translate(glm::vec3 pos) {
	transformationMatrix *= glm::translate(glm::mat4(1.0f), pos);
}

void Transformation::scale(float size) {
	transformationMatrix *= glm::scale(glm::mat4(1.0f), glm::vec3(size));
}

glm::mat4 Transformation::getMatrix() {
	return transformationMatrix;
}