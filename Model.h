#pragma once
#include <GL/glew.h>
#include <glm/vec4.hpp> 
#include <vector>

class Model 
{
private:
	GLuint VAO = 0;
public:
	Model(float data[]);
	~Model();
	GLuint getVAO();

};

