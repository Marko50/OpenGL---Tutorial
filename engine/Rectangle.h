//
// Created by user on 06-07-2017.
//

#ifndef GAMEENGINE_RECTANGLE_H
#define GAMEENGINE_RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape{
private:
    unsigned int EBO;
public:
    Rectangle(vertexArgs va, colArgs ca, texArgs ta, Shader* shader)
            : Shape(ta, shader){

        this->initGLBuffers(va,ca,ta);
    }
    void initGLBuffers(vertexArgs va, colArgs ca, texArgs ta);
    void draw();
};

#endif //GAMEENGINE_RECTANGLE_H
