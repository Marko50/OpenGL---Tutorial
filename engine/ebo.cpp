//
// Created by user on 06-07-2017.
//

#include "ebo.h"


void ebo::initGLBuffers(vertexArgs va, colArgs ca, texArgs ta) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, va.infSize, va.inf, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, va.indSize, va.ind, GL_STATIC_DRAW);

    //position
    glVertexAttribPointer(this->shader->layoutLocationVertex, 3, GL_FLOAT, GL_FALSE, va.sizeNextVertex, (void*) va.posFirstVertex);
    glEnableVertexAttribArray(this->shader->layoutLocationVertex);

    if(ca.col){
        glVertexAttribPointer(this->shader->layoutLocationColor,3,GL_FLOAT,GL_FALSE, ca.sizeNextColor,(void *) ca.posFirstColor);
        glEnableVertexAttribArray(this->shader->layoutLocationColor);
    }

    if(ta.tex){
        glVertexAttribPointer(this->shader->layoutLocationTex, 2 , GL_FLOAT, GL_FALSE, ta.sizeNextTex, (void *) ta.posFirstTex);
        glEnableVertexAttribArray(this->shader->layoutLocationTex);
    }

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);
    glUseProgram(this->shader->ID);
}

void ebo::draw() {
    glUseProgram(this->shader->ID);
    this->updateTransform("transformTrans","transformRot","transformScale");
    this->updateCoordinates("model");
    this->changeColor(1.0f,0.0f,1.0f, 1.0f, "color");
    for(unsigned int i = 0; i < this->textures.size(); i++){
        glActiveTexture(this->textures[i]->getTextureUnit());
        glBindTexture(GL_TEXTURE_2D, this->textures[i]->getTexture());
    }
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, this->numOfVert, GL_UNSIGNED_INT, 0);
}