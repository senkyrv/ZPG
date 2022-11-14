#include "DirectionalLight.h"

/*DirectionalLight::DirectionalLight()
{
	this->direction = glm::vec3(-0.2f, -1.0f, -0.3f);
}*/

DirectionalLight::DirectionalLight(glm::vec3 direction)
{
	this->direction = direction;
}

DirectionalLight::~DirectionalLight()
{
}