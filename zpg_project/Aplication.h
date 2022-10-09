#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include "Callback.h"
#include "Shader.h"
#include "Model.h"

class Aplication
{
private:
	static Aplication *app;	
	Shader *shader;		

public:
	static Aplication* getApp();
	~Aplication();
	void Run();
};

