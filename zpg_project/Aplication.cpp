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


	// Projection matrix : 45� Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.01f, 100.0f);

	// Camera matrix
	glm::mat4 View = glm::lookAt(
		glm::vec3(10, 10, 10), // Camera is at (4,3,-3), in World Space
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
	);
	// Model matrix : an identity matrix (model will be at the origin)
	glm::mat4 ModelMat = glm::mat4(1.0f);

	GLFWwindow* window;
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

	std::vector<ModelData> triangle = {
    { { -0.1f, 0.5f, 0.0f, 1 }, { 1, 0, 0, 1 } },
    { { -0.9f, -0.5f, 0.0f, 1 }, { 0, 1, 0, 1 } },
    { { -0.1f, -0.5f, 0.0f, 1 }, { 0, 0, 1, 1 } },
	};

	std::vector<ModelData> triangle2 = {
	{ { 0.1f, 0.5f, 0.0f, 1 }, { 1, 0, 0, 1 } },
	{ { 0.9f, -0.5f, 0.0f, 1 }, { 0, 1, 0, 1 } },
	{ { 0.1f, -0.5f, 0.0f, 1 }, { 0, 0, 1, 1 } },
	};

	glm::mat4 M = glm::mat4(1.0f);

	//M = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.3f, 0.0f));

	M = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));

	//M = glm::rotate(M,90.0f, glm::vec3(1.0f, 0.0f, 0.0f));

	Model* model = new Model(triangle);
	Model* model2 = new Model(triangle2);

	shader = new Shader();

	while (!glfwWindowShouldClose(window)) {
		// clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(shader->getShaderProgram());
		glBindVertexArray(model->getVAO());

		GLint idModelTransform = glGetUniformLocation(shader->getShaderProgram(), "modelMatrix");
		if (idModelTransform == -1) {
			fprintf(stderr, "Model matrix not found \n");
		}
		glUniformMatrix4fv(idModelTransform, 1, GL_FALSE, &M[0][0]);


		// draw triangles
		glDrawArrays(GL_TRIANGLES, 0, 3);  // mode,first,count

		glUseProgram(shader->getShaderProgram());
		glBindVertexArray(model2->getVAO());

		// draw triangles
		glDrawArrays(GL_TRIANGLES, 0, 3);  // mode,first,count
		
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
