#pragma once
#include <GL/glew.h>
#include <glm/vec4.hpp> 
#include <vector>
#include "AbstractModel.h"


class ModelGift : public AbstractModel
{

public:
	ModelGift();
	~ModelGift();
	void draw(Shader* shader, Transformation* transformation) override;

};

