//
// Created by user on 06-07-2017.
//

#ifndef GAMEENGINE_RECTANGLE_H
#define GAMEENGINE_RECTANGLE_H

#include "Shape.h"

class ebo: public Shape{
private:
    unsigned int EBO;
public:
    ebo(vertexArgs va, colArgs ca, texArgs ta, Shader* shader, State* st)
            : Shape(ta, shader,st){

        this->initGLBuffers(va,ca,ta);
    }
    void initGLBuffers(vertexArgs va, colArgs ca, texArgs ta);
    void draw();
};

#endif //GAMEENGINE_RECTANGLE_H
