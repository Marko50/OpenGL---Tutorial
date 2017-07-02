//
// Created by user on 27-06-2017.
//

#include "../deps/glad/glad.h"
#include "../include/GLFW/glfw3.h"
#include <iostream>

#ifndef GAMEENGINE_WINDOW_H
#define GAMEENGINE_WINDOW_H

#endif //GAMEENGINE_WINDOW_H

//2 Triangles --> Exercise 1
float vertices2[] = {
        //first triangle
        -1.0f, 0.0f, 0.0f, // left
        0.0f, 1.0f, 0.0f, // right
        -1.0f,  1.0f, 0.0f, // top
        //second triangle
        -1.0f, 0.0f, 0.0f, // left
        0.0f, 1.0f, 0.0f, // right
        0.0f,  0.0f, 0.0f, // top
};

//1st Triangle --> Exercise 2
float vertices3[] = {
        //first triangle
        -1.0f, 0.0f, 0.0f, // left
        0.0f, 1.0f, 0.0f, // right
        -1.0f,  1.0f, 0.0f, // top
};

//2nd Triangle --> Exercise 2
float vertices4[] = {
        -1.0f, 0.0f, 0.0f, // left
        0.0f, 1.0f, 0.0f, // right
        0.0f,  0.0f, 0.0f, // top
};

//Rectangle vertices --> Tutorial
float vertices[] = {
        0.5f,  0.5f, 0.0f,  // top right
        0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left
};

//Rectangle indexes --> Tutorial
unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
};

const char * firstshadder = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "\n"
        "void main()\n"
        "{\n"
        "    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";

const char * secondshader = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "\n"
        "void main()\n"
        "{\n"
        "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\n\0";


const char * secondshaderb = "#version 330 core\n"  //Exercise 3
        "out vec4 FragColor;\n"
        "\n"
        "void main()\n"
        "{\n"
        "    FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
        "}\n\0";


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void initGLBuffers(unsigned int& VAO, unsigned int& VBO,unsigned int& EBO, float vert[], int size);
int vertexInit(unsigned int& vertexShader, unsigned int& fragmentShader, unsigned int& shaderProgram, int shad);
void renderLoop(GLFWwindow* window, unsigned int shaderProgram[], unsigned int VAO[], unsigned int EBO[]);