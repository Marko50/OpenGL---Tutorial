//
// Created by user on 12-09-2017.
//

#ifndef GAMEENGINE_SPOTLIGHT_H
#define GAMEENGINE_SPOTLIGHT_H
#include "vbo.h"
#include "lightVBO.h"


class SpotLight : public lightVBO {
    glm::vec3 direction;
    float cutOff;
    float outerCutOff;
    float constant;
    float linear;
    float quadratic;
public:
    static unsigned int count;
    SpotLight(const vertexArgs &va, const texArgs &ta, const normalArgs & na) : lightVBO(va,ta,na){
        this->direction = glm::vec3(1,0,0);
        this->cutOff = glm::cos(glm::radians(12.5f));
        this->outerCutOff = glm::cos(glm::radians(15.0f));
        this->constant = 1.0f;
        this->linear = 0.09f;
        this->quadratic = 0.032f;
        this->id = count;
        count ++;
    }
    void draw();
    void updateDirection(const char * dir);
    void updatePosition(const char * pos);
    void updateAngles(const char * cutOff, const char * outerCutOff, const char * constant, const char * linear, const char * quadratic);
    void setConstant(float constant) {
            SpotLight::constant = constant;
    }

    void setQuadratic(float quadratic) {
            SpotLight::quadratic = quadratic;
    }

    void setLinear(float linear) {
            SpotLight::linear = linear;
    }

    void setOuterCutOff(float outerCutOff) {
            SpotLight::outerCutOff = outerCutOff;
    }

    void setCutOff(float cutOff) {
            SpotLight::cutOff = cutOff;
    }

    void setDirection(const glm::vec3 &direction) {
            SpotLight::direction = direction;
    }
};


#endif //GAMEENGINE_SPOTLIGHT_H
