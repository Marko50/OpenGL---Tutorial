//
// Created by user on 06-07-2017.
//

#ifndef GAMEENGINE_SHAPE_H
#define GAMEENGINE_SHAPE_H

#include "shader.h"
#include "Texture.h"
#include <vector>


struct vertexArgs{
    float * inf;
    int * ind;
    int indSize;
    int infSize;
    int sizeNextVertex;
    int posFirstVertex;
    int numOfVert;
};

struct colArgs{
    bool col;
    int sizeNextColor;
    int posFirstColor;
};

struct texArgs{
    bool tex;
    int sizeNextTex;
    int posFirstTex;
    std:: vector<Texture * > text;
};

class Shape{
protected:
    float x,y,z;
    float sizex,sizey,sizez;
    float degrees;
    bool rotX,rotY,rotZ;
    int numOfVert;
    unsigned int VAO;
    unsigned int VBO;
    Shader* shader;
    std::vector<Texture *> textures;
    glm::mat4 m;
    glm::mat4 v;
    glm::mat4 p;
public:
    Shape(vertexArgs va, texArgs ta, Shader* shader);
    virtual  void initGLBuffers(vertexArgs va, colArgs ca, texArgs ta) = 0;
    virtual void draw() = 0;
    void translate(float x, float y, float z);
    void scale(float x, float y, float z);
    void rotate(float degres, bool x, bool y, bool z);
    void updateCoordinates(const char * model, const char * view,const char * projection);
    void changeColor(float R, float G, float B, float O, const char * uniformName);
    void updateTransform(const char *uniformTrans, const char * uniformRot, const char * uniformScale);
    void layDown();
    ~Shape(){
        delete shader;
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
    };
    const glm::mat4 &getM() const {
        return m;
    }

    void setM(const glm::mat4 &m) {
        Shape::m = m;
    }

    const glm::mat4 &getV() const {
        return v;
    }

    void setV(const glm::mat4 &v) {
        Shape::v = v;
    }

    const glm::mat4 &getP() const {
        return p;
    }

    void setP(const glm::mat4 &p) {
        Shape::p = p;
    }

    float getX() const {
        return x;
    }

    float getY() const {
        return y;
    }

    float getZ() const {
        return z;
    }

    float getSizex() const {
        return sizex;
    }

    float getSizey() const {
        return sizey;
    }

    float getSizez() const {
        return sizez;
    }

    float getDegrees() const {
        return degrees;
    }





};

#endif //GAMEENGINE_SHAPE_H