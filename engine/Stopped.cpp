//
// Created by user on 15-07-2017.
//

#include "Stopped.h"

Stopped::Stopped(const char *u) : State(u) { }

void Stopped::action(unsigned int ID) {
    glUseProgram(ID);
    glm::mat4 trans;
    trans = glm::translate(trans, glm::vec3(0,0,0));
    unsigned int transformLoc = glGetUniformLocation(ID,uniformTransf);
    glUniformMatrix4fv(transformLoc,1,GL_FALSE,glm::value_ptr(trans));
}