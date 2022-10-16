#pragma once

// Include GLFW
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

#include <vector>

#include "Camera.h"

class CallbackController {
private:
    static CallbackController* callbackController;
    CallbackController();
    std::vector<Camera*> cameras;

public:
    static CallbackController* getInstance();
    ~CallbackController();
    void cursorPosCallback(GLFWwindow* window, double mouseXPos,
        double mouseYPos);
    void registerCamera(Camera* camera);
};