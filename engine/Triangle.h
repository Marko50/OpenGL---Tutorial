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
            : Shape(va, ca,ta,shader){
        this->initGLBuffers(ta.textureCount, ta.uniformName);
    }
    void initGLBuffers(std::vector<int> textureCount, std::vector<const char *> uniformName);
    void draw();
};

#endif //GAMEENGINE_TRIANGLE_H
