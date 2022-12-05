#include "Shader.h"
#include "Camera.h"
#include "glm/gtc/type_ptr.hpp"
#include <SOIL.h>

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

void Shader::update(Camera* camera) {
    glUseProgram(getShaderProgram());
    GLint idProjectionMatrix =
        glGetUniformLocation(shaderProgramId, "projectionMatrix");
    if (idProjectionMatrix == -1) {
        fprintf(stderr, "ProjectionMatrix not found \n");
    }
    glUniformMatrix4fv(idProjectionMatrix, 1, GL_FALSE, &camera->projectionMatrix[0][0]);

    GLint idViewMatrix = glGetUniformLocation(shaderProgramId, "viewMatrix");
    if (idViewMatrix == -1) {
        fprintf(stderr, "ViewMatrix not found \n");
    }
    glUniformMatrix4fv(idViewMatrix, 1, GL_FALSE, &camera->getCameraLookAt()[0][0]);

    glUniform3fv(glGetUniformLocation(shaderProgramID, "viewPos"), 1, &camera->eye[0]);

    if (lightsIn) {
        addLights();
    }

    glUseProgram(0);
}

void Shader::addLights()
{
    lightsIn = true;

    //LIGHTS, NEED TO FIX LOCATION IN CODE
    // 
    //DirectionalLight* dl = new DirectionalLight(glm::vec3(-3.2f, 3.0f, -3.3f));
    //glUniform3fv(glGetUniformLocation(this->shaderProgramID, "lights[0].direction"), 1, glm::value_ptr(dl->direction));

    //DirectionalLight* dl = new DirectionalLight(glm::vec3(0.0f, 5.0f, 0.0f));
    //glUniform3fv(glGetUniformLocation(this->shaderProgramID, "lights[0].position"), 1, glm::value_ptr(dl->direction));


   //DirectionalLight* dl = new DirectionalLight(glm::vec3(-3.2f, 3.0f, -3.3f));
    GLint idDirLight = glGetUniformLocation(this->shaderProgramID, "lights[0].direction");
    if (idDirLight == -1) {
        fprintf(stderr, "DirLight not found \n");
    }
    glUniform3fv(idDirLight, 1, glm::value_ptr(dl->direction));


    /*PointLight* pl = new PointLight(glm::vec3(0.0f, 5.0f, 0.0f));
    GLint idPointLight = glGetUniformLocation(this->shaderProgramID, "lights[0].position");
    if (idPointLight == -1) {
        fprintf(stderr, "PointLight not found \n");
    }

    glUniform3fv(idPointLight, 1, glm::value_ptr(pl->position));*/

    /*ReflectorLight* rl = new ReflectorLight(glm::vec3(0.0f, 5.0f, 0.0f), glm::vec3(-3.2f, 3.0f, -3.3f), glm::cos(glm::radians(12.5f)));
    GLint idPointLight = glGetUniformLocation(this->shaderProgramID, "lights[0].position");
    if (idPointLight == -1) {
    fprintf(stderr, "PointLight not found \n");
    }
    glUniform3fv(glGetUniformLocation(this->shaderProgramID, "lights[0].position"), 1, glm::value_ptr(rl->position));
    glUniform3fv(glGetUniformLocation(this->shaderProgramID, "lights[0].direction"), 1, glm::value_ptr(rl->direction));
    glUniform1f(glGetUniformLocation(this->shaderProgramID, "lights[0].reflectionRadius"), rl->reflectionRadius);*/
}


GLuint Shader::getShaderProgram() {
    return this->shaderProgramId;
}

//Shader::Shader(const char* vertexFile, const char* fragmentFile, const char* fileName)
//{
//    //isTextured = true;
//    shaderProgramId = loadShader(vertexFile, fragmentFile);
//    // create and compile shaders
//    /*GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &vertex_shader, NULL);
//    glCompileShader(vertexShader);
//    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &fragment_shader, NULL);
//    glCompileShader(fragmentShader);
//    this->shaderProgramId = glCreateProgram();
//    glAttachShader(shaderProgramId, fragmentShader);
//    glAttachShader(shaderProgramId, vertexShader);
//    glLinkProgram(shaderProgramId); */
//
//    GLint status;
//    glGetProgramiv(shaderProgramId, GL_LINK_STATUS, &status);
//    if (status == GL_FALSE) {
//        GLint infoLogLength;
//        glGetProgramiv(shaderProgramId, GL_INFO_LOG_LENGTH, &infoLogLength);
//        GLchar* strInfoLog = new GLchar[infoLogLength + 1];
//        glGetProgramInfoLog(shaderProgramId, infoLogLength, NULL, strInfoLog);
//        fprintf(stderr, "Linker failure: %s\n", strInfoLog);
//        delete[] strInfoLog;
//        exit(EXIT_FAILURE);
//    }
//
//    //Texture* texture = new Texture(fileName, textureId++);
//    //texture->applyTexture(shaderProgramId);
//}
//
//Shader::Shader(const char* vertexFile, const char* fragmentFile, const char* file_xpos, const char* file_xneg, const char* file_ypos, const char* file_yneg, const char* file_zpos, const char* file_zneg)
//{
//    shaderProgramId = loadShader(vertexFile, fragmentFile);
//    // create and compile shaders
//    /*GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &vertex_shader, NULL);
//    glCompileShader(vertexShader);
//    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &fragment_shader, NULL);
//    glCompileShader(fragmentShader);
//    this->shaderProgramId = glCreateProgram();
//    glAttachShader(shaderProgramId, fragmentShader);
//    glAttachShader(shaderProgramId, vertexShader);
//    glLinkProgram(shaderProgramId); */
//
//    GLint status;
//    glGetProgramiv(shaderProgramId, GL_LINK_STATUS, &status);
//    if (status == GL_FALSE) {
//        GLint infoLogLength;
//        glGetProgramiv(shaderProgramId, GL_INFO_LOG_LENGTH, &infoLogLength);
//        GLchar* strInfoLog = new GLchar[infoLogLength + 1];
//        glGetProgramInfoLog(shaderProgramId, infoLogLength, NULL, strInfoLog);
//        fprintf(stderr, "Linker failure: %s\n", strInfoLog);
//        delete[] strInfoLog;
//        exit(EXIT_FAILURE);
//    }
//
//    //Texture* texture = new Texture(file_xpos, file_xneg, file_ypos, file_yneg, file_zpos, file_zneg, textureId++);
//    //texture->applyTexture(shaderProgramId);
//}

//void Shader::loadTexture(const char* fileName)
//{
//    glActiveTexture(GL_TEXTURE0 + textureId);
//
//    GLint imageId = SOIL_load_OGL_texture(fileName, SOIL_LOAD_RGB, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_MIPMAPS);
//    if (imageId == NULL) {
//        std::cout << "An error occurred while loading image." << std::endl;
//        exit(EXIT_FAILURE);
//    }
//
//    glBindTexture(GL_TEXTURE_2D, imageId);
//
//}
//
//void Shader::applyTexture()
//{
//
//    //Set texture unit to fragment shader
//    GLint uniformID = glGetUniformLocation(getShaderProgram(), "textureUnitID");
//    if (uniformID == -1) {
//        fprintf(stderr, "TEXTURE not found \n");
//    }
//
//    glUniform1i(uniformID, textureId);
//}


Shader::~Shader() {}