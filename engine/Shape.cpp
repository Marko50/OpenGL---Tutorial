//
// Created by user on 06-07-2017.
//

#include "Shape.h"

Shape::Shape(texArgs ta, Shader* shad){
    this->shader  = shad;
    this->textures = ta.text;
}

void Shape::rotate(bool x, bool y, bool z, float degrees, const char *uniformTransf) {
    glUseProgram(this->shader->ID);
    glm::mat4 trans;
    trans = glm::rotate(trans,glm::radians(degrees),glm::vec3((int)x, int(y),(int)z));
    unsigned int transformLoc = glGetUniformLocation(this->shader->ID,uniformTransf);
    glUniformMatrix4fv(transformLoc,1,GL_FALSE,glm::value_ptr(trans));
}

void Shape::translate(float x, float y, float z, const char *uniformTransf) {
    glUseProgram(this->shader->ID);
    glm::mat4 trans;
    trans = glm::translate(trans, glm::vec3(x,y,z));
    unsigned int transformLoc = glGetUniformLocation(this->shader->ID,uniformTransf);
    glUniformMatrix4fv(transformLoc,1,GL_FALSE,glm::value_ptr(trans));
}


void Shape::scale(float x, float y, float z, const char *uniformTransf) {
    glUseProgram(this->shader->ID);
    glm::mat4 trans;
    trans = glm::scale(trans, glm::vec3(x,y,z));
    unsigned int transformLoc = glGetUniformLocation(this->shader->ID,uniformTransf);
    glUniformMatrix4fv(transformLoc,1,GL_FALSE,glm::value_ptr(trans));
}

void Shape::changeColor(float R, float  G, float  B, float  O) {
    this->shader->set4f("color",R,G,B,O);
}