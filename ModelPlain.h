#pragma once
#include <GL/glew.h>
#include <glm/vec4.hpp> 
#include <vector>
#include "plain.h"
#include "AbstractModel.h"


class ModelPlain : public AbstractModel
{

public:
	Texture* texture;
	ModelPlain();
	ModelPlain(Texture* texture);// constructor for model with texture, yet just enter any int, NEED TO EDIT!
	~ModelPlain();
	void draw(Shader* shader, Transformation* transformation) override;


};

