#include "CallbackController.h"

CallbackController* CallbackController::callbackController = nullptr;

void CallbackController::cursorCallback(GLFWwindow* window, double mouseX,
    double mouseY) {
    for (auto c : cameras) {
        c->refreshMousePosition(mouseX, mouseY);
    }
}

void CallbackController::registerCamera(Camera* camera) {
    cameras.push_back(camera);
}

void CallbackController::processInput(GLFWwindow* window, int key) {

    if (key == GLFW_KEY_W) {
        for (auto c : cameras) {
            c->toFront();
        }
    }

    if (key == GLFW_KEY_A) {
        for (auto c : cameras) {
            c->toLeft();
        }
    }

    if (key == GLFW_KEY_S) {
        for (auto c : cameras) {
            c->toBack();
        }
    }

    if (key == GLFW_KEY_D) {
        for (auto c : cameras) {
            c->toRight();
        }
    }
}

CallbackController* CallbackController::getInstance() {
    if (!callbackController) {
        callbackController = new CallbackController();
    }
    return callbackController;
}

void CallbackController::windowResizeCallback(GLFWwindow* window, int width,
    int height) {
    for (auto c : cameras) {
        c->resize(width, height);
    }
    glViewport(0, 0, width, height);
}

CallbackController::CallbackController() {}

CallbackController::~CallbackController() {}