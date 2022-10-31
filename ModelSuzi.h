#pragma once
#include <GL/glew.h>
#include <glm/vec4.hpp> 
#include <vector>
#include "suzi_flat.h"
#include "AbstractModel.h"


class ModelSuzi : public AbstractModel
{

public:
	ModelSuzi();
	~ModelSuzi();
	void draw(Shader* shader, Transformation* transformation) override;

};

