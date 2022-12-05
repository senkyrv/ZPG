#pragma once
#include <GL/glew.h>
#include <stdio.h>
#include <stdlib.h>
#include "ShaderLoader.h"
#include "PointLight.h"
#include "DirectionalLight.h"
#include "ReflectorLight.h"
#include "Texture.h"

class Camera;
class Shader : public ShaderLoader{
private:
    GLuint shaderProgramId;
    bool lightsIn = false;
    //GLint imageId = 0;
    //int textureId = 0;


public:
    DirectionalLight* dl = new DirectionalLight(glm::vec3(-3.2f, 3.0f, -3.3f));
    //bool isTextured = false;
    const char* vertex_shader =
        "#version 330\n"
        "layout(location=0) in vec4 vp;"
        "layout(location = 1) in vec4 color;"
        "out vec4 vColor;"
        "uniform mat4 modelMatrix;"
        "uniform mat4 viewMatrix;"
        "uniform mat4 projectionMatrix;"
        "void main () {"
        "     gl_Position = (projectionMatrix * viewMatrix * modelMatrix) * vp;"
        "     vColor = color;"
        "}";

    const char* fragment_shader =
        "#version 330\n"
        "in vec4 vColor;"
        "out vec4 fColor;"
        "void main () {"
        "fColor = vColor;"
        "}";

    Shader(const char* vertexFile, const char* fragmentFile);
    //Shader(const char* vertexFile, const char* fragmentFile, const char* fileName);
    //Shader(const char* vertexFile, const char* fragmentFile, const char* file_xpos, const char* file_xneg, const char* file_ypos, const char* file_yneg, const char* file_zpos, const char* file_zneg);
    ~Shader();
    GLuint getShaderProgram();
    //void loadTexture(const char* fileName);
    //void applyTexture();
    void refreshCamera(Camera* camera);
    void addLights();
};