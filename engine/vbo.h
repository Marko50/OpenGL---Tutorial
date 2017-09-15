//
// Created by user on 06-07-2017.
//

#ifndef GAMEENGINE_TRIANGLE_H
#define GAMEENGINE_TRIANGLE_H

#include "Shape.h"
#include <vector>

class vbo: public Shape{
private:
    std::vector<Texture *> textures;
public:
    static Shader *shader;
    vbo(vertexArgs va, texArgs ta, normalArgs na)
            : Shape(va){
        this->shader = new Shader("files/vertexShader", "files/fragmentShader", createShaderArgs(0,1,2));
        this->textures = ta.text;
        this->initGLBuffers(va,ta,na);
    }
    void initGLBuffers(vertexArgs va, texArgs ta,normalArgs na);
    void draw();
    void updateCoordinates(const char * model);
    void updateNormals(const char * uniform);
};

#endif //GAMEENGINE_TRIANGLE_H
