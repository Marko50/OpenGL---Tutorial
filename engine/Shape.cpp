//
// Created by user on 06-07-2017.
//

#include "Shape.h"

shaderArgs createShaderArgs(int lposVer, int lPosColor, int lPosTex){
    shaderArgs sa;
    sa.layoutLocationVertex = lposVer;
    sa.layoutLocationColor = lPosColor;
    sa.layoutLocationTex = lPosTex;
    return  sa;
}

Shape::Shape(vertexArgs va,texArgs ta ,glm::vec4 c){
    this->shader =  new Shader("files/vertexShader", "files/fragmentShader", createShaderArgs(0,1,2));
    this->color = c;
    this->scale(1,1,1);
    this->translate(0.0,0,0);
    this->rotate(0,true,true,true);
    this->numOfVert = va.numOfVert;
    this->textures = ta.text;
    this->m = glm::rotate(m, glm::radians(20.0f),glm::vec3(1.0f,0.3f,0.5f));
}
Shader * Shape::shader = 0;


void Shape::updateCoordinates(const char *model) {
    this->shader->setMatrix4fv(model, m);
}

void Shape::updateColor(const char *uniformName) {
    this->shader->set4f(uniformName, this->color.x, this->color.y, this->color.z, this->color.w);
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
