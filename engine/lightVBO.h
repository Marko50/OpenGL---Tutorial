//
// Created by user on 25-07-2017.
//

#ifndef GAMEENGINE_LIGHTVBO_H
#define GAMEENGINE_LIGHTVBO_H


#include "vbo.h"

class lightVBO : public vbo {
    glm::vec3 lightColor;
public:
    lightVBO(const vertexArgs &va, const texArgs &ta, const normalArgs & na, const glm::vec3 &c) : vbo(va, ta, na, glm::vec4(1.0f)){
        this->lightColor = c;
    }
    void updateLightColor(const char * uniformLight);
    void setAmbient(const char * uniformAmbient);
    void updateLightPos(const char * uniformLightPos);
    void draw();
    void changeLightColor(float R, float G, float B);
};


#endif //GAMEENGINE_LIGHTVBO_H