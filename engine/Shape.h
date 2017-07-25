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

struct texArgs{
    bool tex;
    int sizeNextTex;
    int posFirstTex;
    std:: vector<Texture * > text;
};

class Shape{
protected:
    glm::vec4 color;
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
    Shape(vertexArgs va, texArgs ta, Shader* shader,glm::vec4 c);
    virtual  void initGLBuffers(vertexArgs va, texArgs ta) = 0;
    virtual void draw() = 0;
    void translate(float x, float y, float z);
    void scale(float x, float y, float z);
    void rotate(float degres, bool x, bool y, bool z);
    void updateCoordinates(const char * model);
    void updateColor(const char * uniformName);
    void updateTransform(const char *uniformTrans, const char * uniformRot, const char * uniformScale);
    ~Shape(){
        delete shader;
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
    };
};

#endif //GAMEENGINE_SHAPE_H