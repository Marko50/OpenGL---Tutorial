//
// Created by user on 12-09-2017.
//

#ifndef GAMEENGINE_DIRECTIONALLIGHT_H
#define GAMEENGINE_DIRECTIONALLIGHT_H


#include "lightVBO.h"

class DirectionalLight: public lightVBO {
    glm::vec3 direction;
    static unsigned int count;
public:
    DirectionalLight (const vertexArgs &va, const texArgs &ta, const normalArgs & na) : lightVBO(va,ta,na){
        this->setDirection(glm::vec3(-0.2f,-1.0f,-0.3f));
        this->id = count;
        count ++;
    }
    void updateDirection(const char * dir);
    void draw();
    void setDirection(const glm::vec3 &direction) {
        DirectionalLight::direction = direction;
    }
};


#endif //GAMEENGINE_DIRECTIONALLIGHT_H
