#include "Aplication.h"

Aplication* Aplication::app = nullptr;

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
#include <stdlib.h>
#include <stdio.h>
void Aplication::Run() {

	prepareForDraw();

	std::vector<ModelData> triangle = {
    { { -0.1f, 0.5f, 0.0f, 1 }, { 1, 0, 0, 1 } },
    { { -0.9f, -0.5f, 0.0f, 1 }, { 0, 1, 0, 1 } },
    { { -0.1f, -0.5f, 0.0f, 1 }, { 0, 0, 1, 1 } },
	};

	std::vector<ModelData> triangle2 = {
	{ { 0.1f, 0.5f, 0.0f, 1 }, { 1, 1, 0, 1 } },
	{ { 0.9f, -0.5f, 0.0f, 1 }, { 0, 1, 1, 1 } },
	{ { 0.1f, -0.5f, 0.0f, 1 }, { 1, 0, 1, 1 } },
	};


	//transformationMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.3f, 0.0f));
	//transformationMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
	//transformationMatrix = glm::rotate(M,90.0f, glm::vec3(1.0f, 0.0f, 0.0f));

	Model* model = new Model(triangle);
	Model* model2 = new Model(triangle2);

	shader = new Shader();

	DrawableObject* do1 = new DrawableObject(model, shader);
	DrawableObject* do2 = new DrawableObject(model2, shader);

	Transformation* t1 = new Transformation();
	Transformation* t2 = new Transformation();

	t1->scale(0.5f);
	
	t2->scale(0.5f);
	t2->translate(glm::vec3(0.0f, 1.0f, 0.0f));
	
	Scene* scene = new Scene();

	while (!glfwWindowShouldClose(window)) {
		// clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		t1->passTransformationMatrix(shader);
		do1->setAndDraw();

		scene->updateCamera();

		t2->passTransformationMatrix(shader);
		do2->setAndDraw();
		
		// update other events like input handling
		glfwPollEvents();
		// put the stuff we’ve been drawing onto the display
		glfwSwapBuffers(window);
	}
	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);
}


Aplication* Aplication::getApp()
{
	if (!app) {
		app = new Aplication();
	}
	return app;
}

Aplication::~Aplication()
{
}

void Aplication::prepareForDraw()
{
	//glfwSetErrorCallback(error_callback);
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		exit(EXIT_FAILURE);
	}

	//inicializace konkretni verze
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE,
		GLFW_OPENGL_CORE_PROFILE);  //

	window = glfwCreateWindow(800, 600, "ZPG", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwSetCursorPosCallback(
		window,
		[](GLFWwindow* window, double mouseXPos, double mouseYPos) -> void {
			CallbackController::getInstance()->cursorPosCallback(window, mouseXPos,
				mouseYPos);
		});
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	CallBack* callBackObject = new CallBack(window);

	// start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();

	// get version info
	printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
	printf("Using GLEW %s\n", glewGetString(GLEW_VERSION));
	printf("Vendor %s\n", glGetString(GL_VENDOR));
	printf("Renderer %s\n", glGetString(GL_RENDERER));
	printf("GLSL %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	int major, minor, revision;
	glfwGetVersion(&major, &minor, &revision);
	printf("Using GLFW %i.%i.%i\n", major, minor, revision);

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	float ratio = width / (float)height;
	glViewport(0, 0, width, height);
}
