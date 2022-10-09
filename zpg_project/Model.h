#pragma once
#include <GL/glew.h>
#include <glm/vec4.hpp> 
#include <vector>

struct ModelData {
	float position[4];
	float rgba[4];
};

class Model 
{
private:
	std::vector<ModelData> model;
	GLuint VAO = 0;
public:
	Model(std::vector<ModelData> model);
	~Model();
	GLuint getVAO();

};

