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
    std::vector<Texture *> textures;
    glm::mat4 m;
public:
    Shader* shader;
    Shape(vertexArgs va, texArgs ta, Shader* shader);
    virtual  void initGLBuffers(vertexArgs va, colArgs ca, texArgs ta) = 0;
    virtual void draw() = 0;
    void translate(float x, float y, float z);
    void scale(float x, float y, float z);
    void rotate(float degres, bool x, bool y, bool z);
    void updateCoordinates(const char * model);
    void changeColor(float R, float G, float B, float O, const char * uniformName);
    void updateTransform(const char *uniformTrans, const char * uniformRot, const char * uniformScale);
    void layDown();
    ~Shape(){
        delete shader;
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
    };
};

#endif //GAMEENGINE_SHAPE_H