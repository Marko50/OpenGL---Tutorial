//
// Created by user on 06-07-2017.
//

#ifndef GAMEENGINE_SHAPE_H
#define GAMEENGINE_SHAPE_H

#include "shader.h"
#include "Texture.h"
#include <vector>

shaderArgs createShaderArgs(int lposVer, int lPosColor, int lPosTex, int lPosNorm);


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

struct normalArgs{
    int sizeNextNorm;
    int posFirstNorm;
};

class Shape{
protected:
    glm::vec3 diffuse;
    glm::vec3 ambient;
    glm::vec3 specular;
    float shininess;
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
    static Shader *shader;
    Shape(vertexArgs va, texArgs ta);
    virtual  void initGLBuffers(vertexArgs va, texArgs ta, normalArgs na) = 0;
    virtual void draw() = 0;
    void setDiffuse(float x,float y, float z);
    void setAmbient(float x, float y, float z);
    void setSpecular(float x, float y, float z);
    void setShininess(float s);
    void updateMaterial(const char * uniformDiff, const char * uniformAmbient, const char * uniformSpec, const char * uniformShini);
    void translate(float x, float y, float z);
    void scale(float x, float y, float z);
    void rotate(float degres, bool x, bool y, bool z);
    void updateCoordinates(const char * model);
    void updateNormals(const char * uniform);
    void updateTransform(const char *uniformTrans, const char * uniformRot, const char * uniformScale);
    ~Shape(){
        delete shader;
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
    };
};

#endif //GAMEENGINE_SHAPE_H