#include "ModelPLain.h"

ModelPlain::ModelPlain()
{
    GLuint VBO = 0;
    // generate the VBO
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(plain), plain, GL_STATIC_DRAW);

    // generate the VAO
    glGenVertexArrays(1, &VAO);
    glEnableVertexAttribArray(0);

    // bind the VAO
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)(3 * sizeof(GL_FLOAT)));
}

ModelPlain::~ModelPlain()
{
}

void ModelPlain::draw(Shader* shader, Transformation* transformation)
{
    glUseProgram(shader->getShaderProgram());
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);  // mode,first,count
    GLint idModelTransform = glGetUniformLocation(shader->getShaderProgram(), "modelMatrix");
    if (idModelTransform == -1) {
        fprintf(stderr, "matrixModel not found \n");
    }
    glUniformMatrix4fv(idModelTransform, 1, GL_FALSE,
        &transformation->getMatrix()[0][0]);
    glUseProgram(0);
}