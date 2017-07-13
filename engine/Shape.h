//
// Created by user on 06-07-2017.
//

#ifndef GAMEENGINE_SHAPE_H
#define GAMEENGINE_SHAPE_H

#include "shader.h"
#include "Texture.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../deps/glad/glad.h"
#include "../include/GLFW/glfw3.h"
#include <vector>


struct vertexArgs{
    float * inf;
    int * ind;
    int indSize;
    int infSize;
    int sizeNextVertex;
    int posFirstVertex;
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
    unsigned int VAO;
    unsigned int VBO;
    Shader* shader;
    std::vector<Texture *> textures;
public:
    Shape(texArgs ta, Shader* shader);
    virtual  void initGLBuffers(vertexArgs va, colArgs ca, texArgs ta) = 0;
    virtual void draw() = 0;
    void changeColor(float R, float  G, float  B, float  O);
    void rotate(bool x, bool y, bool z, float degrees, const char * uniformTransf);
    void translate(float x, float y, float z, const char * uniformTransf);
    void scale(float x, float y, float z, const char * uniformTransf);
    ~Shape(){
        delete shader;
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
    };
};

#endif //GAMEENGINE_SHAPE_H