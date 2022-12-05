#include "ModelSky.h"

ModelSky::ModelSky(Texture* texture)
{

    glGenBuffers(1, &VBO); // generate the VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(skycube), &skycube[0], GL_STATIC_DRAW);

    glGenVertexArrays(1, &VAO); //generate the VAO
    glBindVertexArray(VAO); //bind the VAO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    //enable vertex attributes
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (GLvoid*)0);

}

ModelSky::~ModelSky()
{
}

void ModelSky::draw(Shader* shader, Transformation* transformation)
{

    glUseProgram(shader->getShaderProgram());
    glBindVertexArray(VAO);
    //glBindBuffer(GL_ARRAY_BUFFER, VBO);

    //GLint idModelTransform = glGetUniformLocation(shader->getShaderProgram(), "modelMatrix");
    //if (idModelTransform == -1) {
    //    fprintf(stderr, "matrixModel not found \n");
    //}
    //glUniformMatrix4fv(idModelTransform, 1, GL_FALSE, &transformation->getMatrix()[0][0]);

    //texture->applyTexture(shader->getShaderProgram());

    glDrawArrays(GL_TRIANGLES, 0, 108);  // mode,first,count


    glClear(GL_DEPTH_BUFFER_BIT);
    glUseProgram(0);

}


