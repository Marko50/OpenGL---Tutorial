//
// Created by user on 06-07-2017.
//

#ifndef GAMEENGINE_TRIANGLE_H
#define GAMEENGINE_TRIANGLE_H

#include "Shape.h"
#include <vector>

class Triangle: public Shape{
private:

public:
    Triangle(vertexArgs va, colArgs ca, texArgs ta, Shader* shader)
            : Shape(ta,shader){
        this->initGLBuffers(va,ca,ta);
    }
    void initGLBuffers(vertexArgs va, colArgs ca, texArgs ta);
    void draw();
};

#endif //GAMEENGINE_TRIANGLE_H
