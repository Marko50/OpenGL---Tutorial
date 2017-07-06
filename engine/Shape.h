//
// Created by user on 06-07-2017.
//

#ifndef GAMEENGINE_SHAPE_H
#define GAMEENGINE_SHAPE_H

#include "shader.h"

class Shape{
protected:
    unsigned int VAO;
    unsigned int VBO;
    Shader* shader;
    float * information;
    int size;
    int sizeForNextVertex;
    int posForFirstVertex;
    int layoutLocationVertex;
    bool colored;
    int sizeForNextColor;
    int posForFirstColor;
    int layoutLocationColor;
public:
    Shape(float inf[], int infSize, int sizeNextVertex, int posFirstVertex, const char * vertexShaderPath, const char * fragmentShaderPath);
    Shape(float inf[], int infSize, int sizeNextVertex, int posFirstVertex, int sizeNextColor, int posFirstColor,const char * vertexShaderPath, const char * fragmentShaderPath);
    virtual  void initGLBuffers() = 0;
    virtual void draw() = 0;
    ~Shape(){delete shader;};
};

#endif //GAMEENGINE_SHAPE_H