//
// Created by user on 27-06-2017.
//

#include <math.h>
#include "Shape.h"
#include "vbo.h"
#include "ebo.h"
#include "Texture.h"
#include "State.h"
#include "Stopped.h"
#include "Rotation.h"
#include "Translation.h"
#include "Scale.h"
#include <iostream>
#include <vector>

#ifndef GAMEENGINE_WINDOW_H
#define GAMEENGINE_WINDOW_H

#endif //GAMEENGINE_WINDOW_H


float vertices1[] = {
        // positions         // colors       // texture coords
        1.0f, 0.0f, 0.0f,  1.0f, 0.0f, 0.0f,   1.0f,0.0f,            // bottom right
        0.0f, 0.0f, 0.0f,  0.0f, 1.0f, 0.0f,   0.0f, 0.0f,                     // bottom left
        0.5f,  1.0f, 0.0f,  0.0f, 0.0f, 1.0f,  0.5f,1.0f                       // top
};


float vertices2[] = {
        // positions          // colors           // texture coords
        0.0f,  1.0f, 0.0f,   1.0f, 0.0f, 0.0f,   0.0f, 1.0f,   // top right
        0.0f, 0.0f, 0.0f,   0.0f, 1.0f, 0.0f,   0.0f, 0.0f,   // bottom right
        -1.0f, 0.0f, 0.0f,   0.0f, 0.0f, 1.0f,   -1.0f, 0.0f,   // bottom left
        -1.0f,  1.0f, 0.0f,   1.0f, 1.0f, 0.0f,   -1.0f, 1.0f    // top left
};



int indices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
};

float vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};



GLFWwindow * CreateWindow();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void renderLoop(GLFWwindow* window, unsigned int c, Shape* shape[]);
texArgs createTexArgs(bool tex,
                      int sizeNextTex,
                      int posFirstTex,
                      std:: vector<Texture * > text);

colArgs createColorArgs( bool col,
                         int sizeNextColor,
                         int posFirstColor);

vertexArgs createVertexArgs(  float * inf,
                              int * ind,
                              int infSize,
                              int sizeNextVertex,
                              int posFirstVertex,
                              int indSize,
                              int numOfVert);

shaderArgs createShaderArgs(int lposVer, int lPosColor, int lPosTex);