#pragma once
#include <glm/vec3.hpp> 

class ReflectorLight {
private:

public:
	glm::vec3 position;
	glm::vec3 direction;
	float reflectionRadius;
	//float constant;
	//float linear;
	//float quadratic;
	ReflectorLight(glm::vec3 position, glm::vec3 direction, float reflectionRadius);
	~ReflectorLight();

};
