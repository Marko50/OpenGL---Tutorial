//
// Created by user on 06-07-2017.
//

#include "Shape.h"

shaderArgs createShaderArgs(int lposVer,  int lNormAgrs, int lPosTex){
    shaderArgs sa;
    sa.layoutLocationVertex = lposVer;
    sa.layoutLocationTex = lPosTex;
    sa.layoutLocationNormals = lNormAgrs;
    return  sa;
}

Shape::Shape(vertexArgs va){
    this->scale(1,1,1);
    this->translate(0.0,0,0);
    this->rotate(0,true,true,true);
    this->numOfVert = va.numOfVert;
    this->m = glm::rotate(m, glm::radians(20.0f),glm::vec3(1.0f,0.3f,0.5f));
}



void Shape::rotate(float degres, bool x, bool y, bool z) {
    this->degrees = degres;
    this->rotX = x;
    this->rotY = y;
    this->rotZ = z;
    this->m = glm::rotate(m, glm::radians(degres),glm::vec3((int) x, (int) y, (int) z));
}

void Shape::translate(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->m = glm::translate(m, glm::vec3(x,y,z));
}

void Shape::scale(float x, float y, float z) {
    this->sizex = x;
    this->sizey = y;
    this->sizez = z;
    this->m = glm::scale(m, glm::vec3(x,y,z));
}
