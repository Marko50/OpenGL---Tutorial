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
#include <vector>


struct vertexArgs{
    float * inf;
    int * ind;
    int infSize;
    int sizeNextVertex;
    int posFirstVertex;
    int layoutPos;
};

struct colArgs{
    bool col;
    int sizeNextColor;
    int posFirstColor;
    int layoutColor;
};

struct texArgs{
    bool tex;
    int sizeNextTex;
    int posFirstTex;
    int layoutText;
    std::vector<int> textureCount;
    std::vector<const char *> uniformName;
    std:: vector<Texture * > text;
};

class Shape{
protected:
    unsigned int VAO;
    unsigned int VBO;
    Shader* shader;
    float * information;
    int size;
    int sizeForNextVertex;
    int posForFirstVertex;
    int layoutLocationVertex;
    bool colored;
    std::vector<Texture *> textures;
    bool textured;
    int sizeForNextColor;
    int posForFirstColor;
    int layoutLocationColor;
    int layoutLocationTex;
    int sizeForNextTex;
    int posForFirstTex;
public:
    Shape(vertexArgs va, colArgs ca, texArgs ta, Shader* shader);
    virtual  void initGLBuffers(std::vector<int> textureCount, std::vector<const char *> uniformName) = 0;
    virtual void draw() = 0;
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