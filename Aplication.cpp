#include "Aplication.h"
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
	//Camera* camera = new Camera();
	CallbackController::getInstance()->registerCamera(camera);


	//Shader* shader = new Shader("phongTextureVertex.glsl", "phongTextureFragment.glsl");
	////shader->addLights();
	//Texture* texture = new Texture("model.png", scene->getAndIncTextureId());

	//camera->attach(shader);

	//Transformation* t = new Transformation();

	//t->scale(1.0f);
	//AbstractModel* am = new ModelAssimp(texture, "model.obj");

	//DrawableObject* dro = new DrawableObject(am, shader, t);

	//scene->insertToScene(dro);




	//Shader* shader = new Shader("textureVertex.glsl", "textureFragment.glsl");
	//Texture* texture = new Texture("watchTower.jpg" ,scene->getAndIncTextureId());
	//Texture* texture2 = new Texture("grass.png", scene->getAndIncTextureId());
	//Texture* texture3 = new Texture("model.png", scene->getAndIncTextureId());
	//Texture* texture4 = new Texture("zombie.png", scene->getAndIncTextureId());

	//camera->attach(shader);

	//Transformation* t = new Transformation();
	//t->scale(1.0f);
	//t->translate(glm::vec3(-7.0f, -0.7f, 0.0f));
	//Transformation* t2 = new Transformation();
	//t2->scale(20.0f);
	//Transformation* t3 = new Transformation();
	//t3->scale(1.0f);
	//t3->translate(glm::vec3(10.0f, 0.0f, 3.0f));

	//AbstractModel* am = new ModelAssimp(texture, "watchTower.obj");
	//AbstractModel* plain = new ModelPlain(texture2);
	//AbstractModel* house = new ModelAssimp(texture3, "model.obj");
	//AbstractModel* zombie = new ModelAssimp(texture4, "zombie.obj");


	//DrawableObject* dro = new DrawableObject(am, shader, t);

	//scene->insertToScene(new DrawableObject(plain, shader, t2));
	//scene->insertToScene(new DrawableObject(house, shader, t3));
	//scene->insertToScene(dro);

	//for (int i = 0; i < 30; i++) {
	//	Transformation* t4 = new Transformation();
	//	float x = rand() % 31 - 15;
	//	float z = rand() % 31 - 15;
	//	t4->translate(glm::vec3(x, 0, z));
	//	t4->scale(1.5f);
	//	t4->rotate(15 * i);
	//	scene->insertToScene(new DrawableObject(zombie, shader, t4));
	//}

	//// SKYBOX TEST
	//sceneSkyboxTest(camera);


	//PHONG TEST

	Shader* shader2 = new Shader("phongVertex.glsl", "phongFragment.glsl");
	//shader2->addLights();
	camera->attach(shader2);
	scenePhongTest(shader2);



	//FOREST SCENE
	//sceneForest(camera);



	// TEST FOR MULTIPLE SHADERS AND 100+ OBJECTS, NEED TO EDIT!!
	//multipleObjectAndShaderTest(camera);



	applyCallbacks();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_STENCIL_TEST);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

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

	glfwSetMouseButtonCallback(
		window, [](GLFWwindow* window, int button, int action, int mods) -> void {
			CallbackController::getInstance()->buttonCallback(window, button,
				action, mods);
		});

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

	window = glfwCreateWindow(windowSize.x, windowSize.y, "ZPG", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	//CallBack* callBackObject = new CallBack(window);

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

void Aplication::scenePhongTest(Shader* shader)
{
	//Phong 1 test + 2 test

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
	scene->insertToScene(do4);
}

void Aplication::sceneForest(Camera* camera)
{
	scene->clickActionAllowed = true;

	Shader* shader = new Shader("textureVertex.glsl", "textureFragment.glsl");
	Texture* texture = new Texture("grass.png", scene->getAndIncTextureId());
	camera->attach(shader);

	Transformation* t = new Transformation();
	t->scale(15.0f);
	t->translate(glm::vec3(0.0f, 0.0f, 0.0f));

	AbstractModel* am = new ModelPlain(texture);

	DrawableObject* dro = new DrawableObject(am, shader, t);

	scene->insertToScene(dro);

	AbstractModel* tree = new ModelTree();
	AbstractModel* suzi = new ModelSuzi();
	AbstractModel* sphere = new ModelBall();
	AbstractModel* gift = new ModelGift();
	AbstractModel* bush = new ModelBush();

	Shader* shader2 = new Shader("phongVertex.glsl", "phongFragment.glsl");
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
		t2->translate(glm::vec3(x, 0.0, z));
		t2->scale(3.0f);
		scene->insertToScene(new DrawableObject(gift, shader2, t2));
	}
}
void Aplication::sceneMultipleObjectAndShaderTest(Camera* camera)
{
	Shader* shader2 = new Shader("textureVertex.glsl", "textureFragment.glsl");
	Texture* texture2 = new Texture("wooden_fence.png", scene->getAndIncTextureId());

	camera->attach(shader2);

	Transformation* t2 = new Transformation();
	t2->scale(20.0f);

	AbstractModel* am2 = new ModelPlain(texture2);

	DrawableObject* dro2 = new DrawableObject(am2, shader2, t2);

	scene->insertToScene(dro2);


	Shader* shader3 = new Shader("phongVertex.glsl", "phongFragment.glsl");
	Shader* shader4 = new Shader("originalVertex.glsl", "originalFragment.glsl");
	Shader* shader5 = new Shader("lambertVertex.glsl", "lambertFragment.glsl");
	camera->attach(shader3);
	camera->attach(shader4);
	camera->attach(shader5);
	AbstractModel* suzi = new ModelSuzi();
	AbstractModel* bush = new ModelBush();
	AbstractModel* gift = new ModelGift();

	for (int i = 0; i < 20; i++) {
		Transformation* t2 = new Transformation();
		float x = rand() % 31 - 15;
		float z = rand() % 31 - 15;
		t2->translate(glm::vec3(x, 0.3, z));
		t2->scale(0.02 * i);
		scene->insertToScene(new DrawableObject(suzi, shader3, t2));
	}
	for (int i = 0; i < 60; i++) {
		Transformation* t2 = new Transformation();
		float x = rand() % 31 - 15;
		float z = rand() % 31 - 15;
		t2->translate(glm::vec3(x, 0, z));
		t2->scale(0.1 * i);
		scene->insertToScene(new DrawableObject(bush, shader4, t2));
	}
	for (int i = 0; i < 20; i++) {
		Transformation* t2 = new Transformation();
		float x = rand() % 31 - 15;
		float z = rand() % 31 - 15;
		t2->translate(glm::vec3(x, 0, z));
		t2->scale(0.4 * i);
		scene->insertToScene(new DrawableObject(gift, shader5, t2));
	}
}
void Aplication::sceneSkyboxTest(Camera* camera)
{
	Shader* shader = new Shader("skyboxVertex.glsl", "skyboxFragment.glsl");
	Texture* texture = new Texture("posx.jpg", "negx.jpg", "posy.jpg", "negy.jpg", "posz.jpg", "negz.jpg", scene->getAndIncTextureId());

	camera->attach(shader);

	Transformation* t = new Transformation();
	t->scale(10.0f);
	t->translate(glm::vec3(0.0f, -0.1f, 0.0f));

	AbstractModel* am = new ModelSky(texture);

	DrawableObject* dro = new DrawableObject(am, shader, t);

	scene->insertToScene(dro);


	Shader* shader2 = new Shader("textureVertex.glsl", "textureFragment.glsl");
	Texture* texture2 = new Texture("grass.png", scene->getAndIncTextureId());

	camera->attach(shader2);


	Transformation* t2 = new Transformation();
	t2->scale(10.0f);
	t2->translate(glm::vec3(0.0f, -0.1f, 0.0f));

	AbstractModel* am2 = new ModelPlain(texture2);

	DrawableObject* dro2 = new DrawableObject(am2, shader2, t2);

	scene->insertToScene(dro2);
}
Scene* Aplication::getScene()
{
	return scene;
}
Aplication* Aplication::app = nullptr;