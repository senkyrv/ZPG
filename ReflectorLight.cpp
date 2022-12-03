#include "ReflectorLight.h"

ReflectorLight::ReflectorLight(glm::vec3 position, glm::vec3 direction, float reflectionRadius)
{
	this->position = position;
	this->direction = direction;
	this->reflectionRadius = reflectionRadius;
}


ReflectorLight::~ReflectorLight()
{
}
