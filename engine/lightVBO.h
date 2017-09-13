//
// Created by user on 25-07-2017.
//

#ifndef GAMEENGINE_LIGHTVBO_H
#define GAMEENGINE_LIGHTVBO_H


#include "vbo.h"
#include <string>
#include <sstream>

class lightVBO : public vbo {
protected:
    unsigned int id;
    glm::vec3 diffuse;
    glm::vec3 specular;
    glm::vec3 ambient;
public:
    static Shader * shader;
    lightVBO(const vertexArgs &va, const texArgs &ta, const normalArgs & na) : vbo(va, ta, na){
        this->shader = new Shader("files/vertexShader2", "files/fragmentShader2", createShaderArgs(0,1,2));
        this->setDiffuse(0.5f, 0.5f, 0.5f);
        this->setSpecular(1.0f, 1.0f, 1.0f);
        this->setAmbient(0.2f, 0.2f, 0.2f);
    }
    void updateCoordinates(const char * model);
    void updateNormals(const char * uniform);
    void updateTransform(const char *uniformTrans, const char * uniformRot, const char * uniformScale);
    void updateLightProperties(const char * type, const char * diffuse, const char * spec, const char * amb);
    void setSpecular(float x, float y, float z);
    void setDiffuse(float x, float y , float z);
    void setAmbient(float x, float y, float z);
    virtual void draw() = 0;
};


#endif //GAMEENGINE_LIGHTVBO_H
