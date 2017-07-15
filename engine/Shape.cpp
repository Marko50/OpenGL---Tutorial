//
// Created by user on 06-07-2017.
//

#include "Shape.h"

Shape::Shape(texArgs ta, Shader* shad, State* st){
    this->shader  = shad;
    this->textures = ta.text;
    this->state = st;
    this->m = glm::rotate(m, glm::radians(45.0f),glm::vec3(1.0f,0.0f,0.0f));
    this->v = glm::translate(v, glm::vec3(0.0f,0.0f,-3.0f));
    this->p = glm::ortho(0.0f,800.0f,0.0f,600.0f,0.1f,100.0f);
}


void Shape::updateCoordinates(const char *model, const char *view,const char *projection) {
    this->shader->setMatrix4fv(model, m);
    this->shader->setMatrix4fv(view, v);
    this->shader->setMatrix4fv(projection, p);
}

void Shape::changeColor(float R, float G, float B, float O, const char *uniformName) {
    this->shader->set4f(uniformName, R,G,B,O);
}