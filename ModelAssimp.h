#pragma once
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "AbstractModel.h"
#include <vector>

class ModelAssimp : public AbstractModel
{
public:
	int count;
	Texture* texture;
	ModelAssimp(Texture* texture, const char* modelFileName);
	~ModelAssimp();
	void draw(Shader* shader, Transformation* transformation) override;
};