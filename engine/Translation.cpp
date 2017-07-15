//
// Created by user on 15-07-2017.
//

#include "Translation.h"


Translation::Translation(const char *u, float x, float y, float z) : State(u) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Translation::action(unsigned int ID) {
    glUseProgram(ID);
    glm::mat4 trans;
    trans = glm::translate(trans, glm::vec3(x,y,z));
    unsigned int transformLoc = glGetUniformLocation(ID,uniformTransf);
    glUniformMatrix4fv(transformLoc,1,GL_FALSE,glm::value_ptr(trans));
}