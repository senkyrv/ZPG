#pragma once
#include <stdio.h>
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <vector>
#include "Shader.h"
#include "Subject.h"

class Shader;
class Camera{
private:
	const float cameraSpeed = 0.5f;
	const float mouseSpeed = 0.3f;

	glm::vec3 target = { 0, 0, 0 };
	glm::vec3 up = { 0, 1, 0 };
	float lastX = 400; // center - half of window
	float lastY = 300;
	std::vector<Shader*> shaders;
	float yaw = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
	float pitch = 0.0f;

public:

	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;

	Camera();
	~Camera();

	glm::vec3 eye = { 0, 10, 6 };
	glm::mat4 getCameraLookAt();


	void toFront();
	void toLeft();
	void toRight();
	void toBack();

	void refreshMousePosition(float newX, float newY);
	void attach(Shader* shader);
	void resize(int width, int height);
	void notify();
};