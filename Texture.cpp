#include "Texture.h"

Texture::Texture(const char* fileName, int textureId)
{
    this->textureId = textureId;
    glActiveTexture(GL_TEXTURE0 + this->textureId);

    GLint imageId = SOIL_load_OGL_texture(fileName, SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    if (imageId == NULL) {
        std::cout << "An error occurred while loading image." << std::endl;
        exit(EXIT_FAILURE);
    }

    glBindTexture(GL_TEXTURE_2D, imageId);

}




Texture::Texture(const char* file_xpos, const char* file_xneg, const char* file_ypos, const char* file_yneg, const char* file_zpos, const char* file_zneg, int textureId)
{

    this->textureId = textureId;
    glActiveTexture(GL_TEXTURE0 + this->textureId);

    GLint imageId = SOIL_load_OGL_cubemap(file_xpos, file_xneg, file_ypos, file_yneg, file_zpos, file_zneg, SOIL_LOAD_RGB, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);
    if (imageId == NULL) {
        std::cout << "An error occurred while loading image." << std::endl;
        exit(EXIT_FAILURE);
    }

    glBindTexture(GL_TEXTURE_2D, imageId);

    glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);
}

void Texture::loadTexture(const char* fileName){}

void Texture::applyTexture(GLuint shaderProgramId)
{
    //Set texture unit to fragment shader
    GLint uniformID = glGetUniformLocation(shaderProgramId, "textureUnitID");
    if (uniformID == -1) {
        fprintf(stderr, "TEXTURE not found \n");
    }

    glUniform1i(uniformID, textureId);
}

Texture::~Texture(){}