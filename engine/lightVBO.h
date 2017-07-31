//
// Created by user on 25-07-2017.
//

#ifndef GAMEENGINE_LIGHTVBO_H
#define GAMEENGINE_LIGHTVBO_H


#include "vbo.h"

class lightVBO : public vbo {
public:
    lightVBO(const vertexArgs &va, const texArgs &ta, const normalArgs & na) : vbo(va, ta, na){
        this->setDiffuse(1.0f,1.0f,1.0f);
        this->setSpecular(1.0f,1.0f,1.0f);
        this->setAmbient(1.0f,1.0f,1.0f);
        this->shininess = 1.0f;
    }
    void updateLightPositon(const char * uniformLightPos);
    void draw();
};


#endif //GAMEENGINE_LIGHTVBO_H
