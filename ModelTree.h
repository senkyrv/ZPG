#pragma once
#include <GL/glew.h>
#include <glm/vec4.hpp> 
#include <vector>
#include "AbstractModel.h"


class ModelTree : public AbstractModel
{

public:
	ModelTree();
	~ModelTree();
	void draw(Shader* shader, Transformation* transformation) override;

};

