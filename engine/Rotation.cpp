//
// Created by user on 15-07-2017.
//

#include "Rotation.h"


Rotation::Rotation(const char *u, bool x, bool y, bool z, float degrees) : State(u) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->degrees = degrees;
}

void Rotation::action(unsigned int ID) {
    glUseProgram(ID);
    glm::mat4 trans;
    trans = glm::rotate(trans,glm::radians(this->degrees),glm::vec3((int)x, int(y),(int)z));
    unsigned int transformLoc = glGetUniformLocation(ID,this->uniformTransf);
    glUniformMatrix4fv(transformLoc,1,GL_FALSE,glm::value_ptr(trans));
}