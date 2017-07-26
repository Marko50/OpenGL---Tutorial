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
    ebo(vertexArgs va,  texArgs ta, normalArgs na ,glm::vec4 c)
            : Shape(va, ta, c){

        this->initGLBuffers(va,ta, na);
    }
    void setAmbient(const char * uniformAmbient);
    void initGLBuffers(vertexArgs va, texArgs ta, normalArgs na);
    void draw();
};

#endif //GAMEENGINE_RECTANGLE_H
