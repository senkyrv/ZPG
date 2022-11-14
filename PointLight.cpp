#include "PointLight.h"

PointLight::PointLight(glm::vec3 position)
{
	this->position = position;
	//printf("POINT LIGHT VEC3 %f %f %f\n", position.x, position.y, position.z);
	//this->constant = constant;
	//this->linear = linear;
	//this->quadratic = quadratic;
}

PointLight::~PointLight()
{

}