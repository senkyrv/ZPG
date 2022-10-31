#pragma once
#include <GL/glew.h>
#include <glm/vec4.hpp> 
#include <vector>
#include "sphere.h"
#include "AbstractModel.h"


class ModelBall : public AbstractModel
{

public:
	ModelBall();
	~ModelBall();
	void draw(Shader* shader, Transformation* transformation) override;

};

