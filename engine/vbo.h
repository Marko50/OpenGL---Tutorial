//
// Created by user on 06-07-2017.
//

#ifndef GAMEENGINE_TRIANGLE_H
#define GAMEENGINE_TRIANGLE_H

#include "Shape.h"
#include <vector>

class vbo: public Shape{
private:

public:
    vbo(vertexArgs va, texArgs ta, normalArgs na,  glm::vec4 c)
            : Shape(va,ta,c){
        this->initGLBuffers(va,ta,na);
    }
    void initGLBuffers(vertexArgs va, texArgs ta,normalArgs na);
    void setAmbient(const char * uniformAmbient);
    void draw();
};

#endif //GAMEENGINE_TRIANGLE_H
