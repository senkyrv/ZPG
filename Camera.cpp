#include "Camera.h"

#include "Shader.h"

void Camera::resize(int width, int height) {

    projectionMatrix = glm::perspective(glm::radians(45.0f), (float)width / height, 0.1f, 100.0f);

}

void Camera::toFront() {
    eye += (glm::normalize(target) * cameraSpeed);
    printf("%f %f %f\n", eye.x, eye.y, eye.z);
    notify();
}
void Camera::toLeft() {
    eye += (glm::normalize(glm::cross(target, up)) * (- cameraSpeed));
    notify();
}
void Camera::toRight() {
    eye += (glm::normalize(glm::cross(target, up)) * cameraSpeed);
    notify();
}
void Camera::toBack() {
    eye += (glm::normalize(target) * (- cameraSpeed));
    notify();
}

void Camera::refreshMousePosition(float newX, float newY) {

    float xpos = static_cast<float>(newX);
    float ypos = static_cast<float>(newY);

    printf("%f %f %f\n", target.x, target.z, target.y);
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; 
    lastX = xpos;
    lastY = ypos;

    xoffset *= mouseSpeed;
    yoffset *= mouseSpeed;

    yaw += xoffset;
    pitch += yoffset;

    if (pitch > 89.0f) {
        pitch = 89.0f;
    }
    if (pitch < -89.0f)
    {
        pitch = -89.0f;
    }


    glm::vec3 dir;
    dir.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    dir.y = sin(glm::radians(pitch));
    dir.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    target = glm::normalize(dir);

    notify();
}

void Camera::notify() {
    for (auto* s : shaders) {
        s->refreshCamera(this);
    }
}

glm::mat4 Camera::getCameraLookAt() {
    return glm::lookAt(eye, eye + target, up);
}

Camera::Camera() {
    projectionMatrix = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
}

void Camera::attach(Shader* shader) {
    shaders.push_back(shader);
}

Camera::~Camera() {}