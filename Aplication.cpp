#include "Aplication.h"

Aplication* Aplication::app = nullptr;
#include <glm/vec3.hpp> 
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtc/type_ptr.hpp>
#include <stdlib.h>
#include <stdio.h>

void Aplication::run() {

	setUpWindow();
	scene = new Scene();

	//setup camera
	Camera* camera = new Camera();
	CallbackController::getInstance()->registerCamera(camera);


	// Triangles
	/*std::vector<ModelData> triangle = {
    { { -0.1f, 0.5f, 0.0f, 1 }, { 1, 0, 0, 1 } },
    { { -0.9f, -0.5f, 0.0f, 1 }, { 0, 1, 0, 1 } },
    { { -0.1f, -0.5f, 0.0f, 1 }, { 0, 0, 1, 1 } },
	};

	std::vector<ModelData> triangle2 = {
	{ { 0.1f, 0.5f, 0.0f, 1 }, { 1, 1, 0, 1 } },
	{ { 0.9f, -0.5f, 0.0f, 1 }, { 0, 1, 1, 1 } },
	{ { 0.1f, -0.5f, 0.0f, 1 }, { 1, 0, 1, 1 } },
	};

	Model* model = new Model(triangle);
	Model* model2 = new Model(triangle2);

	Transformation* t1 = new Transformation();
	Transformation* t2 = new Transformation();

	t1->scale(0.5f);

	t2->scale(0.5f);
	t2->translate(glm::vec3(0.0f, 1.0f, 0.0f)); */

	

	//Shader* shader2 = new Shader("lambertVertex.txt", "lambertFragment.txt");
	



	
	//camera->registerShader(shader);
	//shader->loadShader("lambertVertex.txt", "lambertFragment.txt");
	//shader2->loadShader("originalVertex.txt", "originalFragment.txt");
	
	//Shader* shader = new Shader("originalVertex.txt", "originalFragment.txt");
	//shader->loadShader("shaders/originalVertex.txt", "shaders/originalFragment.txt");
	
	//camera->attacg(shader2);


	


	//DrawableObject* do3 = new DrawableObject(mb, shader, t2);
	//scene->addObject(do3);
	//scene->addObject(new DrawableObject(model, shader, t2));
	//scene->addObject(new DrawableObject(model2, shader, t1));
	
	//Phong 1 test + 2 test
	Shader* shader = new Shader("textureVertex.glsl", "textureFragment.glsl", "wooden_fence.png");

	camera->attach(shader);

	Transformation* t = new Transformation();
	t->scale(10.0f);

	AbstractModel* am = new ModelPlain();

	DrawableObject* dro = new DrawableObject(am, shader, t);

	scene->insertToScene(dro);

	/*
	Transformation* t1 = new Transformation();
	Transformation* t2 = new Transformation();
	Transformation* t3 = new Transformation();
	Transformation* t4 = new Transformation();

	t1->translate(glm::vec3(1.4f, 0.0f, 1.4f));
	t2->translate(glm::vec3(-1.4f, 0.0f, 1.4f));
	t3->translate(glm::vec3(1.4f, 0.0f, -1.4f));
	t4->translate(glm::vec3(-1.4f, 0.0f, -1.4f));

	AbstractModel* am1 = new ModelBall();
	AbstractModel* am2 = new ModelBall();
	AbstractModel* am3 = new ModelBall();
	AbstractModel* am4 = new ModelBall();

	DrawableObject* do1 = new DrawableObject(am1, shader, t1);
	DrawableObject* do2 = new DrawableObject(am2, shader, t2);
	DrawableObject* do3 = new DrawableObject(am3, shader, t3);
	DrawableObject* do4 = new DrawableObject(am4, shader, t4);
	scene->insertToScene(do2);
	scene->insertToScene(do1);

	scene->insertToScene(do3);
	scene->insertToScene(do4);*/

	/*Shader* shader = new Shader("phongVertex.txt", "phongFragment.txt");
	Shader* shader2 = new Shader("lambertVertex.txt", "lambertFragment.txt");
	camera->attach(shader);
	camera->attach(shader2);

	Transformation* t1 = new Transformation();
	Transformation* t2 = new Transformation();

	t1->translate(glm::vec3(1.4f, 0.0f, 1.4f));
	t2->translate(glm::vec3(5.4f, 0.0f, 1.4f));


	AbstractModel* am1 = new ModelGift();
	AbstractModel* am2 = new ModelGift();
	scene->insertToScene(new DrawableObject(am1, shader, t1));
	scene->insertToScene(new DrawableObject(am2, shader2, t2));*/
	/*
	Shader* shader = new Shader("originalVertex.txt", "originalFragment.txt");
	camera->attach(shader);

	AbstractModel* am1 = new ModelPlain();
	Transformation* t1 = new Transformation();

	t1->scale(15.0f);
	t1->translate(glm::vec3(0, 0, 0));

	scene->insertToScene(new DrawableObject(am1, shader, t1));

	AbstractModel* tree = new ModelTree();
	AbstractModel* suzi = new ModelSuzi();
	AbstractModel* sphere = new ModelBall();
	AbstractModel* gift = new ModelGift();
	AbstractModel* bush = new ModelBush();




	Shader* shader2 = new Shader("lambertVertex.txt", "lambertFragment.txt");
	camera->attach(shader2);

	//h-d+1 + d
	for (int i = 0; i < 20; i++) {
		Transformation* t2 = new Transformation();
		float x = rand() % 31 - 15;
		float z = rand() % 31 - 15;
		t2->translate(glm::vec3(x, 0, z));
		t2->scale(0.5);
		scene->insertToScene(new DrawableObject(tree, shader2, t2));
	}
	
	for (int i = 0; i < 20; i++) {
		Transformation* t2 = new Transformation();
		float x = rand() % 31 - 15;
		float z = rand() % 31 - 15;
		t2->translate(glm::vec3(x, 0.3, z));
		t2->scale(0.3);
		scene->insertToScene(new DrawableObject(sphere, shader2, t2));
	}

	Shader* shader3 = new Shader("phongVertex.txt", "phongFragment.txt");
	camera->attach(shader3);

	for (int i = 0; i < 20; i++) {
		Transformation* t2 = new Transformation();
		float x = rand() % 31 - 15;
		float z = rand() % 31 - 15;
		t2->translate(glm::vec3(x, 0.3, z));
		t2->scale(0.3);
		scene->insertToScene(new DrawableObject(suzi, shader3, t2));
	}
	for (int i = 0; i < 60; i++) {
		Transformation* t2 = new Transformation();
		float x = rand() % 31 - 15;
		float z = rand() % 31 - 15;
		t2->translate(glm::vec3(x, 0, z));
		t2->scale(1.2);
		scene->insertToScene(new DrawableObject(bush, shader3, t2));
	}
	for (int i = 0; i < 20; i++) {
		Transformation* t2 = new Transformation();
		float x = rand() % 31 - 15;
		float z = rand() % 31 - 15;
		t2->translate(glm::vec3(x, 0, z));
		t2->scale(1.8);
		scene->insertToScene(new DrawableObject(gift, shader3, t2));
	}*/




	applyCallbacks();

	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(window)) {


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		scene->draw();
		
		glfwPollEvents();
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

void Aplication::applyCallbacks() {
	glfwSetCursorPosCallback(window, [](GLFWwindow* window, double mouseXPos, double mouseYPos) -> void {
		CallbackController::getInstance()->cursorCallback(window, mouseXPos, mouseYPos);
		});

	glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) -> void {
		CallbackController::getInstance()->processInput(window, key);
		});

	glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) -> void {
			CallbackController::getInstance()->windowResizeCallback(window, width, height);
		});
}

void Aplication::setUpWindow()
{
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		exit(EXIT_FAILURE);
	}

	////version init
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(800, 600, "ZPG", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwSetCursorPosCallback(
		window,
		[](GLFWwindow* window, double mouseXPos, double mouseYPos) -> void {
			CallbackController::getInstance()->cursorCallback(window, mouseXPos,
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
