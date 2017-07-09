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
    Rectangle(bool col, bool tex, float inf[],int * ind,  int infSize, int sizeNextVertex, int posFirstVertex, int sizeNextColor, int posFirstColor, int sizeNextTex, int posFirstTex, int layoutPos, int layoutColor, int layoutText, Shader* shape)
            : Shape(col, tex, inf, infSize, sizeNextVertex, posFirstVertex,sizeNextColor, posFirstColor,sizeNextTex,posFirstTex,layoutPos,layoutColor,layoutText, shape){
        indices = ind;
        this->indSize = size;
        this->initGLBuffers();
    }
    void initGLBuffers();
    void draw();
};

#endif //GAMEENGINE_RECTANGLE_H
