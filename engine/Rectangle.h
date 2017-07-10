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
    Rectangle(bool col, bool tex, float inf[],int * ind,  int infSize, int sizeNextVertex, int posFirstVertex, int sizeNextColor, int posFirstColor, int sizeNextTex, int posFirstTex, int layoutPos, int layoutColor, int layoutText, Shader* shape, std::vector<Texture *> t, std::vector<int> tCount , std::vector<const char *> uniformName)
            : Shape(col, tex, inf, infSize, sizeNextVertex, posFirstVertex,sizeNextColor, posFirstColor,sizeNextTex,posFirstTex,layoutPos,layoutColor,layoutText, shape, t){
        indices = ind;
        this->indSize = size;
        this->initGLBuffers(tCount, uniformName);
    }
    void initGLBuffers(std::vector<int> tCount , std::vector<const char *> uniformName);
    void draw();
};

#endif //GAMEENGINE_RECTANGLE_H
