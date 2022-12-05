#pragma once
#include <stdio.h>
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <vector>
#include "Shader.h"
#include "Subject.h"

class Shader;
class Camera : public Subject{
private:
	const float cameraSpeed = 0.5f;
	const float mouseSpeed = 0.3f;

	glm::vec3 target = { 0, 0, 0 };
	glm::vec3 up = { 0, 1, 0 };
	float lastX = 400; // center - half of window
	float lastY = 300;
	std::vector<Shader*> shaders;
	float yaw = -90.0f;	// yaw is initialized to -90.0, 0.0 pointing to the right for positive x, wed be too much in right side
	float pitch = 0.0f;

public:

	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;

	Camera();
	~Camera();

	glm::vec3 eye = { -5, 10, 5 };
	glm::mat4 getCameraLookAt();


	void toFront();
	void toLeft();
	void toRight();
	void toBack();

	void refreshMousePosition(float newX, float newY);
	//void attach(Shader* shader);
	//void detach(Shader* shader)override;
	void resize(int width, int height);
	//void notify();
};