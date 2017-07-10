//
// Created by user on 06-07-2017.
//

#include "Triangle.h"


void Triangle ::initGLBuffers(std::vector<int> textureCount, std::vector<const char *> uniformName) {
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glGenBuffers(1, &VBO);


    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, size , information, GL_STATIC_DRAW);


    //position
    glVertexAttribPointer(this->layoutLocationVertex,3,GL_FLOAT,GL_FALSE, this->sizeForNextVertex, (void *) this->posForFirstVertex);
    glEnableVertexAttribArray(this->layoutLocationVertex);


    //color
    if(this->colored){
        glVertexAttribPointer(this->layoutLocationColor,3,GL_FLOAT,GL_FALSE, this->sizeForNextColor,(void *) this->posForFirstColor);
        glEnableVertexAttribArray(this->layoutLocationColor);
    }

    //texture
    if(this->textured){
        glVertexAttribPointer(this->layoutLocationTex, 2 , GL_FLOAT, GL_FALSE, this->sizeForNextTex, (void *) this->posForFirstTex);
        glEnableVertexAttribArray(this->layoutLocationTex);
    }

    //unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    glUseProgram(this->shader->ID);
    for(int i = 0; i < uniformName.size(); i++){
        this->shader->setInt(uniformName[i], textureCount[i]);
    }

}

void Triangle::draw() {
    glUseProgram(this->shader->ID);
    for(unsigned int i = 0; i < this->textures.size(); i++){
        glActiveTexture(this->textures[i]->getTextureUnit());
        glBindTexture(GL_TEXTURE_2D, this->textures[i]->getTexture());
    }
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0,3);
}