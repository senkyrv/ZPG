#pragma once
#include <GL/glew.h>
#include <glm/vec4.hpp> 
#include <vector>
#include "plain.h"
#include "AbstractModel.h"


class ModelPlain : public AbstractModel
{

public:
	ModelPlain();
	~ModelPlain();
	void draw(Shader* shader, Transformation* transformation) override;

};

