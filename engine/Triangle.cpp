//
// Created by user on 06-07-2017.
//

#include "Triangle.h"


void Triangle ::initGLBuffers() {
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

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);


    glUseProgram(this->shader->ID);
}

void Triangle::draw() {
    glUseProgram(this->shader->ID);
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0,3);
}