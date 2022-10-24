#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include "Callback.h"
#include "Shader.h"
#include "Model.h"
#include "DrawableObject.h"
#include "Transformation.h"
#include "CallbackController.h"
#include "Camera.h"
#include "Scene.h"

class Aplication
{
private:

	static Aplication *app;		
	GLFWwindow* window;
	Scene* scene;

public:

	static Aplication* getApp();
	~Aplication();
	void prepareForDraw();
	void Run();
	void setCallbacks();
};

