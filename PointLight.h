#pragma once
#include <glm/vec3.hpp> 

class PointLight {
private:

public:
	glm::vec3 position;
	//float constant;
	//float linear;
	//float quadratic;
	PointLight(glm::vec3 position);
	~PointLight();

};