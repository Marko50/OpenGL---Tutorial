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
    static Shader *shader;
    vbo(vertexArgs va, texArgs ta, normalArgs na)
            : Shape(va,ta){
        this->shader = new Shader("files/vertexShader", "files/fragmentShader", createShaderArgs(0,1,2));
        this->initGLBuffers(va,ta,na);
    }
    void initGLBuffers(vertexArgs va, texArgs ta,normalArgs na);
    void draw();
    void updateCoordinates(const char * model);
    void updateNormals(const char * uniform);
    void updateTransform(const char *uniformTrans, const char * uniformRot, const char * uniformScale);
};

#endif //GAMEENGINE_TRIANGLE_H
