//
// Created by user on 15-07-2017.
//

#ifndef GAMEENGINE_STATE_H
#define GAMEENGINE_STATE_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../deps/glad/glad.h"
#include "../include/GLFW/glfw3.h"

class State {
protected:
    const char * uniformTransf;
public:
    State(const char * u);
    virtual void action(unsigned int ID) = 0;
};


#endif //GAMEENGINE_STATE_H
