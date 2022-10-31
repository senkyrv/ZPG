#pragma once
#include <GL/glew.h>
#include <glm/vec4.hpp> 
#include "Shader.h"
#include "Transformation.h"

class AbstractModel{
protected:
	GLuint VAO = 0;

public:
	virtual void draw(Shader* shader, Transformation* transform) = 0;
};