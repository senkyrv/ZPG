#pragma once
#include <GL/glew.h>
#include <glm/vec4.hpp> 
#include <vector>
#include "sphere.h"

class ModelBall
{
private:
	//std::vector model[];
	GLuint VAO = 0;
public:
	ModelBall();
	~ModelBall();
	GLuint getVAO();

};

