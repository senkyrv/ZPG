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

glm::mat4 Transformation::getMatrix() {
	return transformationMatrix;
}
Transformation::Transformation()
{
}

Transformation::~Transformation()
{
}
