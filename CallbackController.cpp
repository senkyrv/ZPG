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

void CallbackController::buttonCallback(GLFWwindow* window, int button, int action, int mode)
{
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {

        GLfloat depth;
        GLuint index;

        // CURSOR POS
        double xpos, ypos;

        glfwGetCursorPos(window, &xpos, &ypos);
        GLint x = (GLint)xpos;
        GLint y = (GLint)ypos;

        glm::vec2 res = Aplication::getApp()->windowSize;
        int newy = res.y - y;

        glReadPixels(x, newy, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth);
        glReadPixels(x, newy, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);

        printf("Clicked on pixel X: %d, Y: %d, Depth %f, Object IndexL: %u\n", x, y, depth, index);

        if (index > 0) {
            Aplication::getApp()->getScene()->removeFromScene(index);
        }

    }
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {

        GLfloat depth;
        GLuint index;

        // CURSOR POS
        double xpos, ypos;

        glfwGetCursorPos(window, &xpos, &ypos);
        GLint x = (GLint)xpos;
        GLint y = (GLint)ypos;

        glm::vec2 res = Aplication::getApp()->windowSize;
        int newy = res.y - y;

        glReadPixels(x, newy, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth);
        glReadPixels(x, newy, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);

        printf("Clicked on pixel X: %d, Y: %d, Depth %f, Object IndexL: %u\n", x, y, depth, index);


        for (auto* o : Aplication::getApp()->getScene()->getDrawableObjects()) {


            glm::vec3 screenX = glm::vec3(x, newy, depth);
            glm::vec4 viewPort = glm::vec4(0, 0, res.x, res.y);
            glm::vec3 pos = glm::unProject(screenX, cameras[0]->getCameraLookAt(),cameras[0]->projectionMatrix, viewPort);

            printf("unProject [%f,%f,%f]\n", pos.x, pos.y, pos.z);

            Aplication::getApp()->getScene()->insertTreeToScene(pos);
            break;
            

        }
    }
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