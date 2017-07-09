//
// Created by user on 06-07-2017.
//

#include "Rectangle.h"

//Rectangle vertices --> Tutorial

void Rectangle::initGLBuffers() {
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


    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);
}

void Rectangle::draw() {

    glUseProgram(this->shader->ID);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}