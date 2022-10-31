#include "Shader.h"
#include "Camera.h"

void Shader::refreshCamera(Camera* camera) {
    glUseProgram(getShaderProgram());
    GLint idProjectionMatrix =
        glGetUniformLocation(shaderProgramId, "projectionMatrix");
    if (idProjectionMatrix == -1) {
        fprintf(stderr, "ProjectionMatrix not found \n");
    }
    glUniformMatrix4fv(idProjectionMatrix, 1, GL_FALSE,
        &camera->projectionMatrix[0][0]);

    GLint idViewMatrix = glGetUniformLocation(shaderProgramId, "viewMatrix");
    if (idViewMatrix == -1) {
        fprintf(stderr, "ViewMatrix not found \n");
    }
    glUniformMatrix4fv(idViewMatrix, 1, GL_FALSE, &camera->getCameraLookAt()[0][0]);

    glUniform3fv(glGetUniformLocation(shaderProgramID, "viewPos"), 1, &camera->eye[0]);
    glUseProgram(0);
}

Shader::Shader(const char* vertexFile, const char* fragmentFile) {
    shaderProgramId = loadShader(vertexFile, fragmentFile);
    // create and compile shaders
    /*GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertex_shader, NULL);
    glCompileShader(vertexShader);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragment_shader, NULL);
    glCompileShader(fragmentShader);
    this->shaderProgramId = glCreateProgram();
    glAttachShader(shaderProgramId, fragmentShader);
    glAttachShader(shaderProgramId, vertexShader);
    glLinkProgram(shaderProgramId); */

    GLint status;
    glGetProgramiv(shaderProgramId, GL_LINK_STATUS, &status);
    if (status == GL_FALSE) {
        GLint infoLogLength;
        glGetProgramiv(shaderProgramId, GL_INFO_LOG_LENGTH, &infoLogLength);
        GLchar* strInfoLog = new GLchar[infoLogLength + 1];
        glGetProgramInfoLog(shaderProgramId, infoLogLength, NULL, strInfoLog);
        fprintf(stderr, "Linker failure: %s\n", strInfoLog);
        delete[] strInfoLog;
        exit(EXIT_FAILURE);
    }
}

GLuint Shader::getShaderProgram(){ 
    return this->shaderProgramId; 
}

Shader::~Shader() {}