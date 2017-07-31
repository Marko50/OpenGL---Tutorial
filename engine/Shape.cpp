//
// Created by user on 06-07-2017.
//

#include "Shape.h"

shaderArgs createShaderArgs(int lposVer, int lPosColor, int lPosTex, int lNormAgrs){
    shaderArgs sa;
    sa.layoutLocationVertex = lposVer;
    sa.layoutLocationColor = lPosColor;
    sa.layoutLocationTex = lPosTex;
    sa.layoutLocationNormals = lNormAgrs;
    return  sa;
}

Shape::Shape(vertexArgs va,texArgs ta ){
    this->shader =  new Shader("files/vertexShader", "files/fragmentShader", createShaderArgs(0,1,2,3));
    this->scale(1,1,1);
    this->translate(0.0,0,0);
    this->rotate(0,true,true,true);
    this->numOfVert = va.numOfVert;
    this->textures = ta.text;
    this->m = glm::rotate(m, glm::radians(20.0f),glm::vec3(1.0f,0.3f,0.5f));
    this->setAmbient(1.0f,0.5f,0.31f);
    this->setDiffuse(1.0f,0.5f,0.31f);
    this->setSpecular(1.0f,1.0f,1.0f);
    this->shininess = 32.0f;
}
Shader * Shape::shader = 0;


void Shape::updateCoordinates(const char *model) {
    this->shader->setMatrix4fv(model, m);
}

void Shape::setAmbient(float x, float y, float z) {
    this->ambient.x = x;
    this->ambient.y = y;
    this->ambient.z = z;
}

void Shape::setDiffuse(float x, float y, float z) {
    this->diffuse.x = x;
    this->diffuse.y = y;
    this->diffuse.z = z;
}

void Shape::setSpecular(float x, float y, float z) {
    this->specular.x = x;
    this->specular.y = y;
    this->specular.z = z;
}

void Shape::setShininess(float s) {
    this->shininess = s;
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

void Shape::updateNormals(const char *uniform) {
    glm::mat4 aux;
    aux = glm::transpose(glm::inverse(this->m));
    this->shader->setMatrix4fv(uniform, aux);
}


void Shape::updateMaterial(const char *uniformDiff, const char *uniformAmbient, const char *uniformSpec,const char * uniformShini) {
    this->shader->set3f(uniformDiff, this->diffuse);
    this->shader->set3f(uniformAmbient, this->ambient);
    this->shader->set3f(uniformSpec, this->specular);
    this->shader->setFloat(uniformShini, this->shininess);
}