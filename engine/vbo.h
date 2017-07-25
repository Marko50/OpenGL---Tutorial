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
    vbo(vertexArgs va, texArgs ta, Shader* shader,glm::vec4 c)
            : Shape(va,ta,shader,c){
        this->initGLBuffers(va,ta);
    }
    void initGLBuffers(vertexArgs va, texArgs ta);
    void draw();
};

#endif //GAMEENGINE_TRIANGLE_H
