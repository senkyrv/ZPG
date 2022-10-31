#pragma once
#include <GL/glew.h>
#include <glm/vec4.hpp> 
#include <vector>
#include "AbstractModel.h"


class ModelBush : public AbstractModel
{

public:
	ModelBush();
	~ModelBush();
	void draw(Shader* shader, Transformation* transformation) override;

};

