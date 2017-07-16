//
// Created by user on 15-07-2017.
//

#include "Scale.h"


Scale::Scale(const char *u, float x, float y, float z) : State(u) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Scale::action(unsigned int ID) {
    float time = (float)glfwGetTime();
    glUseProgram(ID);
    glm::mat4 trans;
    trans = glm::scale(trans, glm::vec3(x*time,y*time,z*time));
    unsigned int transformLoc = glGetUniformLocation(ID,uniformTransf);
    glUniformMatrix4fv(transformLoc,1,GL_FALSE,glm::value_ptr(trans));
}