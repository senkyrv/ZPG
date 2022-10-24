#pragma once
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp>
#include <stdlib.h>
#include <stdio.h>
#include "Shader.h"

class Transformation {
private:

	glm::mat4 transformationMatrix;

public:

	Transformation();
	void scale(float size);
	void rotate(float angel);
	void translate(glm::vec3 pos);
	glm::mat4 getMatrix();
	~Transformation();
};