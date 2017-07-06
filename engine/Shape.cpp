//
// Created by user on 06-07-2017.
//

#include "Shape.h"


Shape::Shape(float * inf, int infSize, int sizeNextVertex, int posFirstVertex, const char *vertexShaderPath, const char *fragmentShaderPath) {
    this->shader  = new Shader(vertexShaderPath,fragmentShaderPath);
    this->information = inf;
    this->size = infSize;
    this->sizeForNextVertex = sizeNextVertex;
    this->posForFirstVertex = posFirstVertex;
    this->layoutLocationVertex = 0;
    this->colored = false;
}

Shape::Shape(float *inf, int infSize, int sizeNextVertex, int posFirstVertex, int sizeNextColor, int posFirstColor,
             const char *vertexShaderPath, const char *fragmentShaderPath) {
    this->shader  = new Shader(vertexShaderPath,fragmentShaderPath);
    this->information = inf;
    this->size = infSize;
    this->sizeForNextVertex = sizeNextVertex;
    this->posForFirstVertex = posFirstVertex;
    this->layoutLocationVertex = 0;
    this->colored = true;
    this->sizeForNextColor = sizeNextColor;
    this->posForFirstColor = posFirstColor;
    this->layoutLocationColor = 1;
}
