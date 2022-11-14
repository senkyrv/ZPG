#pragma once
#include <glm/vec3.hpp> 
class DirectionalLight
{
private:


public:
	glm::vec3 direction;
	DirectionalLight(glm::vec3 direction);
	~DirectionalLight();
};