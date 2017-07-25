//
// Created by user on 25-07-2017.
//

#ifndef GAMEENGINE_LIGHTVBO_H
#define GAMEENGINE_LIGHTVBO_H


#include "vbo.h"

class lightVBO : public vbo {
    glm::vec3 lightColor;
public:
    lightVBO(const vertexArgs &va, const texArgs &ta, Shader *shader, const glm::vec3 &c) : vbo(va, ta, shader, glm::vec4(1.0f)){
        this->lightColor = c;
    }
    void updateLightColor(const char * uniformLight);
    void draw();
    void changeLightColor(float R, float G, float B);
};


#endif //GAMEENGINE_LIGHTVBO_H
