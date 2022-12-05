#pragma once
#include <GL/glew.h>
#include <glm/vec4.hpp> 
#include "Shader.h"
#include "Transformation.h"
#include "Texture.h"

class AbstractModel{
protected:
	GLuint VAO = 0;
	GLuint VBO = 0;
	//bool isTextured = false;

public:
	virtual void draw(Shader* shader, Transformation* transform) = 0;
	//virtual void draw(Shader* shader, Transformation* transformation, Texture* texture) = 0;
};