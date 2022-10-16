#include "Model.h"
#include "Shader.h"

class DrawableObject {

private:
	Model* model;
	Shader* shader;

public:
	DrawableObject(Model* model, Shader* shader);
	void setAndDraw();
	~DrawableObject();
};
