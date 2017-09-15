//
// Created by user on 12-09-2017.
//

#ifndef GAMEENGINE_POINTLIGHT_H
#define GAMEENGINE_POINTLIGHT_H


#include "lightVBO.h"

class PointLight : public lightVBO {
    float constant;
    float linear;
    float quadratic;
public:
    static unsigned int count;
    PointLight (const vertexArgs &va) : lightVBO(va){
        this->setQuadratic(0.032f);
        this->setLinear(0.0f);
        this->setConstant(1.0f);
        this->id = count;
        count ++;
    }
    void draw();
    void updatePosition(const char * pos);
    void updateAttenuation(const char * constant, const char * linear, const char * quadratic);
    void setQuadratic(float quadratic) {
        PointLight::quadratic = quadratic;
    }

    void setLinear(float linear) {
        PointLight::linear = linear;
    }

    void setConstant(float constant) {
        PointLight::constant = constant;
    }


};


#endif //GAMEENGINE_POINTLIGHT_H
