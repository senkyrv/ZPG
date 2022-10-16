#include "Model.h"

Model::Model(std::vector<ModelData> model)
{  
    GLuint VBO = 0;
    // generate the VBO
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(model.at(0)) * model.size(),model.data(), GL_STATIC_DRAW);


    // generate the VAO
    glGenVertexArrays(1, &VAO);
    glEnableVertexAttribArray(0);

    // bind the VAO
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);    
    

    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(model.at(0)),
        (GLvoid*)0);

    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(model.at(0)),
        (GLvoid*)(4 * sizeof(GL_FLOAT)));
}

GLuint Model::getVAO()
{
	return this->VAO;
}

Model::~Model()
{
}
