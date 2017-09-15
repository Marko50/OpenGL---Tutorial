//
// Created by user on 06-07-2017.
//

#ifndef GAMEENGINE_SHAPE_H
#define GAMEENGINE_SHAPE_H

#include "shader.h"
#include "Texture.h"
#include <vector>

shaderArgs createShaderArgs(int lposVer,  int lPosNorm, int lPosTex);


struct vertexArgs{
    float * inf;
    int infSize;
    int sizeNextVertex;
    int posFirstVertex;
    int numOfVert;
};

struct texArgs{
    int sizeNextTex;
    int posFirstTex;
    std:: vector<Texture * > text;
};

struct normalArgs{
    int sizeNextNorm;
    int posFirstNorm;
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
    glm::mat4 m;
public:
    Shape(vertexArgs va);
    virtual void draw() = 0;
    void translate(float x, float y, float z);
    void scale(float x, float y, float z);
    void rotate(float degres, bool x, bool y, bool z);
    virtual void updateCoordinates(const char * model) = 0;
    virtual void updateNormals(const char * uniform) = 0;
    virtual void updateTransform(const char *uniformTrans, const char * uniformRot, const char * uniformScale) = 0;
    ~Shape(){
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
    };
};

#endif //GAMEENGINE_SHAPE_H