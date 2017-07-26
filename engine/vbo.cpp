//
// Created by user on 06-07-2017.
//

#include "vbo.h"


void vbo ::initGLBuffers(vertexArgs va, texArgs ta, normalArgs na) {
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glGenBuffers(1, &VBO);



    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, va.infSize , va.inf, GL_STATIC_DRAW);


    //position
    glVertexAttribPointer(this->shader->layoutLocationVertex,3,GL_FLOAT,GL_FALSE, va.sizeNextVertex, (void *) va.posFirstVertex);
    glEnableVertexAttribArray(this->shader->layoutLocationVertex);


    glVertexAttribPointer(this->shader->layoutLocationNormals, 3 , GL_FLOAT, GL_FALSE, na.sizeNextNorm, (void *) na.posFirstNorm);
    glEnableVertexAttribArray(this->shader->layoutLocationNormals);


    //texture
    if(ta.tex){
        glVertexAttribPointer(this->shader->layoutLocationTex, 2 , GL_FLOAT, GL_FALSE, ta.sizeNextTex, (void *) ta.posFirstTex);
        glEnableVertexAttribArray(this->shader->layoutLocationTex);
    }

    //unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

}

void vbo::draw() {
    this->updateTransform("transformTrans","transformRot","transformScale" );
    this->updateCoordinates("model");
    this->updateColor("color");
    this->setAmbient("ambientStrength");
    this->updateNormals("modelChanged");
    for(unsigned int i = 0; i < this->textures.size(); i++){
        glActiveTexture(this->textures[i]->getTextureUnit());
        glBindTexture(GL_TEXTURE_2D, this->textures[i]->getTexture());
    }
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0,this->numOfVert);
}

void vbo::setAmbient(const char *uniformAmbient) {
    this->shader->setFloat(uniformAmbient, 0.1f);
}