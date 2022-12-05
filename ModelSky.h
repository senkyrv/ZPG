#pragma once
#include <GL/glew.h>
#include <glm/vec4.hpp> 
#include <vector>
#include "skycube.h"
#include "AbstractModel.h"
#include "Texture.h"

class ModelSky : public AbstractModel
{

public:
	Texture* texture;
	ModelSky(Texture* texture);
	~ModelSky();
	void draw(Shader* shader, Transformation* transformation) override;

};


