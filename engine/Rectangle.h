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
    Rectangle(int size, int *ind, float *inf, int infSize, int sizeNextVertex, int posFirstVertex, const char * vertexShaderPath, const char * fragmentShaderPath) : Shape(inf,infSize,sizeNextVertex,posFirstVertex, vertexShaderPath, fragmentShaderPath){
        indices = ind;
        this->indSize = size;
        this->initGLBuffers();
    }
    Rectangle(int size, int * ind, float *inf, int infSize, int sizeNextVertex, int posFirstVertex, int sizeNextColor, int posFirstColor,
              const char *vertexShaderPath, const char *fragmentShaderPath) : Shape(inf,infSize, sizeNextVertex,posFirstVertex, sizeNextColor, posFirstColor, vertexShaderPath, fragmentShaderPath){
        indices = ind;
        this->indSize = size;
        this->initGLBuffers();
    }
    void initGLBuffers();
    void draw();
};

#endif //GAMEENGINE_RECTANGLE_H
