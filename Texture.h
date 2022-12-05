#pragma once
#include <GL/glew.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <SOIL.h>


class Texture {
private:

    //GLint imageId =0;
    int textureId = 0;

public:

    Texture(const char* fileName, int textureId);
    Texture(const char* file_xpos, const char* file_xneg, const char* file_ypos, const char* file_yneg, const char* file_zpos, const char* file_zneg, int textureId);
    ~Texture();

    void loadTexture(const char* fileName);
    void applyTexture(GLuint shaderProgramId);

};