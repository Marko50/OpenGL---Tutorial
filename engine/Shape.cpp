//
// Created by user on 06-07-2017.
//

#include "Shape.h"

Shape::Shape(vertexArgs va, colArgs ca, texArgs ta, Shader* shad){
    this->shader  = shad;
    this->information = va.inf;
    this->size = va.infSize;
    this->sizeForNextVertex = va.sizeNextVertex;
    this->posForFirstVertex = va.posFirstVertex;
    this->layoutLocationVertex = va.layoutPos;
    this->colored = ca.col;
    this->sizeForNextColor = ca.sizeNextColor;
    this->posForFirstColor = ca.posFirstColor;
    this->layoutLocationColor = ca.layoutColor;
    this->textured = ta.tex;
    this->sizeForNextTex = ta.sizeNextTex;
    this->posForFirstTex = ta.posFirstTex;
    this->layoutLocationTex = ta.layoutText;
    this->textures = ta.text;
}

void Shape::rotate(bool x, bool y, bool z, float degrees, const char *uniformTransf) {
    glm::mat4 trans;
    trans = glm::rotate(trans,glm::radians(degrees),glm::vec3((int)x, int(y),(int)z));
    unsigned int transformLoc = glGetUniformLocation(this->shader->ID,uniformTransf);
    glUniformMatrix4fv(transformLoc,1,GL_FALSE,glm::value_ptr(trans));
}

void Shape::translate(float x, float y, float z, const char *uniformTransf) {
    glm::mat4 trans;
    trans = glm::translate(trans, glm::vec3(x,y,z));
    unsigned int transformLoc = glGetUniformLocation(this->shader->ID,uniformTransf);
    glUniformMatrix4fv(transformLoc,1,GL_FALSE,glm::value_ptr(trans));
}


void Shape::scale(float x, float y, float z, const char *uniformTransf) {
    glm::mat4 trans;
    trans = glm::scale(trans, glm::vec3(x,y,z));
    unsigned int transformLoc = glGetUniformLocation(this->shader->ID,uniformTransf);
    glUniformMatrix4fv(transformLoc,1,GL_FALSE,glm::value_ptr(trans));
}