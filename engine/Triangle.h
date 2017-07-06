//
// Created by user on 06-07-2017.
//

#ifndef GAMEENGINE_TRIANGLE_H
#define GAMEENGINE_TRIANGLE_H

#include "Shape.h"

class Triangle: public Shape{
private:

public:
    Triangle(float inf[], int infSize, int sizeNextVertex, int posFirstVertex, const char * vertexShaderPath, const char * fragmentShaderPath) : Shape(inf,infSize,sizeNextVertex,posFirstVertex, vertexShaderPath, fragmentShaderPath){
        this->initGLBuffers();
    }
    Triangle(float *inf, int infSize, int sizeNextVertex, int posFirstVertex, int sizeNextColor, int posFirstColor,
             const char *vertexShaderPath, const char *fragmentShaderPath) : Shape(inf,infSize, sizeNextVertex,posFirstVertex, sizeNextColor, posFirstColor, vertexShaderPath, fragmentShaderPath){
        this->initGLBuffers();
    }
    void initGLBuffers();
    void draw();
};

#endif //GAMEENGINE_TRIANGLE_H
