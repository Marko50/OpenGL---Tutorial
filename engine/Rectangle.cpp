//
// Created by user on 06-07-2017.
//

#include "Rectangle.h"


void Rectangle::initGLBuffers(std::vector<int> tCount , std::vector<const char *> uniformName) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, size, information, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indSize, indices, GL_STATIC_DRAW);

    //position
    glVertexAttribPointer(this->layoutLocationVertex, 3, GL_FLOAT, GL_FALSE, this->sizeForNextVertex, (void*) this->posForFirstVertex);
    glEnableVertexAttribArray(this->layoutLocationVertex);

    if(this->colored){
        glVertexAttribPointer(this->layoutLocationColor,3,GL_FLOAT,GL_FALSE, this->sizeForNextColor,(void *) this->posForFirstColor);
        glEnableVertexAttribArray(this->layoutLocationColor);
    }

    if(this->textured){
        glVertexAttribPointer(this->layoutLocationTex, 2 , GL_FLOAT, GL_FALSE, this->sizeForNextTex, (void *) this->posForFirstTex);
        glEnableVertexAttribArray(this->layoutLocationTex);
    }

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);
    glUseProgram(this->shader->ID);
    this->translate(0,0,0, uniformName[0]);
    this->rotate(false,false,false,0.0f,uniformName[0]);
    this->scale(1,1,1,uniformName[0]);
    for(unsigned int i = 1; i < uniformName.size(); i++){
        this->shader->setInt(uniformName[i], tCount[i]);
    }
}

void Rectangle::draw() {
    for(unsigned int i = 0; i < this->textures.size(); i++){
        glActiveTexture(this->textures[i]->getTextureUnit());
        glBindTexture(GL_TEXTURE_2D, this->textures[i]->getTexture());
    }

    glUseProgram(this->shader->ID);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}