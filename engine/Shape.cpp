//
// Created by user on 06-07-2017.
//

#include "Shape.h"

Shape::Shape(vertexArgs va,texArgs ta, Shader* shad){
    this->scale(1,1,1);
    this->translate(0.0,0,0);
    this->rotate(0,true,true,true);
    this->numOfVert = va.numOfVert;
    this->shader  = shad;
    this->textures = ta.text;
    this->m = glm::rotate(m, glm::radians(0.0f),glm::vec3(1.0f,0.0f,0.0f));
    this->v = glm::translate(v, glm::vec3(0.0f,0.0f,-3.0f));
    //this->p = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, 0.1f, 100.0f);
    this->p = glm::perspective(glm::radians(45.0f), (float) 800 / (float) 600, 0.1f, 100.0f);
}


void Shape::updateCoordinates(const char *model, const char *view,const char *projection) {
    this->shader->setMatrix4fv(model, m);
    this->shader->setMatrix4fv(view, v);
    this->shader->setMatrix4fv(projection, p);
}

void Shape::changeColor(float R, float G, float B, float O, const char *uniformName) {
    this->shader->set4f(uniformName, R,G,B,O);
}

void Shape::rotate(float degres, bool x, bool y, bool z) {
    this->degrees = degres;
    this->rotX = x;
    this->rotY = y;
    this->rotZ = z;
}

void Shape::translate(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Shape::scale(float x, float y, float z) {
    this->sizex = x;
    this->sizey = y;
    this->sizez = z;
}

void Shape::updateTransform(const char *uniformTrans, const char * uniformRot, const char * uniformScale) {
    glm::mat4 trans;
    trans = glm::rotate(trans, glm::radians(this->degrees), glm::vec3((int)this->rotX, (int)this->rotY, (int)this->rotZ));
    this->shader->setMatrix4fv(uniformRot, trans);
    glm::mat4 trans2;
    trans2 = glm::translate(trans2, glm::vec3(this->x,this->y,this->z));
    this->shader->setMatrix4fv(uniformTrans, trans2);
    glm::mat4 trans3;
    trans3 = glm::scale(trans3, glm::vec3(this->sizex, this->sizey,this->sizez));
    this->shader->setMatrix4fv(uniformScale, trans3);
}

void Shape::layDown() {
    this->m = glm::rotate(m, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    this->v = glm::translate(v, glm::vec3(0.0f, 0.0f, -3.0f));
    this->p = glm::perspective(glm::radians(45.0f), (float) 800 / (float) 600, 0.1f, 100.0f);
}