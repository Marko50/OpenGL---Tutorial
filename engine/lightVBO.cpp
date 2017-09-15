//
// Created by user on 25-07-2017.
//

#include "lightVBO.h"

Shader * lightVBO:: shader = 0;


void lightVBO::initGLBuffers(vertexArgs va) {
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, va.infSize , va.inf, GL_STATIC_DRAW);


    //position
    glVertexAttribPointer(this->shader->layoutLocationVertex,3,GL_FLOAT,GL_FALSE, va.sizeNextVertex, (void *) va.posFirstVertex);
    glEnableVertexAttribArray(this->shader->layoutLocationVertex);



    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}




void lightVBO::updateNormals(const char *uniform) {
    glm::mat4 aux;
    aux = glm::transpose(glm::inverse(this->m));
    this->shader->setMatrix4fv(uniform, aux);
}

void lightVBO::updateCoordinates(const char *model) {
    this->shader->setMatrix4fv(model, m);
}

void lightVBO::updateLightProperties(const char * type, const char * diffuse, const char * spec, const char * amb) {
    std::string d,s,a;
    std::string aux = type;
    aux += "[";
    std::stringstream ss;
    ss << this->id;
    aux += ss.str();
    aux += "].";
    d = aux + diffuse;
    s = aux + spec;
    a = aux + amb;
    vbo::shader->set3f(d, this->diffuse);
    vbo::shader->set3f(s, this->specular);
    vbo::shader->set3f(a, this->ambient);
}

void lightVBO::setDiffuse(float x, float y, float z) {
    this->diffuse.x = x;
    this->diffuse.y = y;
    this->diffuse.z = z;
}

void lightVBO::setSpecular(float x, float y, float z) {
    this->specular.x = x;
    this->specular.y = y;
    this->specular.z = z;
}

void lightVBO::setAmbient(float x, float y, float z) {
    this->ambient.x = x;
    this->ambient.y = y;
    this->ambient.z = z;
}


