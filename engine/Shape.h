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
    bool textured;
    int sizeForNextColor;
    int posForFirstColor;
    int layoutLocationColor;
    int layoutLocationTex;
    int sizeForNextTex;
    int posForFirstTex;
public:
    Shape(bool col, bool tex, float inf[], int infSize, int sizeNextVertex, int posFirstVertex, int sizeNextColor, int posFirstColor, int sizeNextTex, int posFirstTex, int layoutPos, int layoutColor, int layoutText, Shader* shape);
    virtual  void initGLBuffers() = 0;
    virtual void draw() = 0;
    ~Shape(){
        delete shader;
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
    };
};

#endif //GAMEENGINE_SHAPE_H