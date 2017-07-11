//
// Created by user on 06-07-2017.
//

#ifndef GAMEENGINE_RECTANGLE_H
#define GAMEENGINE_RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape{
private:
    int * indices;
    unsigned int EBO;
    int indSize;
public:
    Rectangle(vertexArgs va, colArgs ca, texArgs ta, Shader* shader)
            : Shape(va,ca,ta, shader){
        indices = va.ind;
        this->indSize = size;
        this->initGLBuffers(ta.textureCount, ta.uniformName);
    }
    void initGLBuffers(std::vector<int> tCount , std::vector<const char *> uniformName);
    void draw();
};

#endif //GAMEENGINE_RECTANGLE_H
