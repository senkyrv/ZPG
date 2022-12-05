#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

#include "Model.h"
#include "Transformation.h"
#include "CallbackController.h"
#include "Camera.h"
#include "DrawableObject.h"
#include "Scene.h"
#include "Callback.h"
#include "Shader.h"

#include "ModelBall.h"
#include "ModelSuzi.h"
#include "ModelBush.h"
#include "ModelGift.h"
#include "ModelTree.h"
#include "ModelPlain.h"
#include "Texture.h"
#include "ModelSky.h"
#include "ModelAssimp.h"

class Scene;
class Aplication
{
private:

	static Aplication *app;		
	GLFWwindow* window;
	Scene* scene;
	Camera* camera = new Camera();

public:

	static Aplication* getApp();
	~Aplication();

	void setUpWindow();
	void run();
	void applyCallbacks();
	void scenePhongTest(Shader* shader);
	void sceneForest(Camera* camera);
	void sceneMultipleObjectAndShaderTest(Camera* camera);
	void sceneSkyboxTest(Camera* camera);
	Scene* getScene();
	glm::vec2 windowSize = { 800, 600 };
};

