//
// Created by user on 27-06-2017.
//

#include <math.h>
#include "../deps/glad/glad.h"
#include "../include/GLFW/glfw3.h"
#include "Shape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include <iostream>

#ifndef GAMEENGINE_WINDOW_H
#define GAMEENGINE_WINDOW_H

#endif //GAMEENGINE_WINDOW_H


float vertices4[] = { //Tutorial
        // positions         // colors
        1.0f, 0.0f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
        0.0f, 0.0f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
        0.5f,  1.0f, 0.0f,  0.0f, 0.0f, 1.0f    // top
};

float vertices5[] = { //Tutorial
        // positions         // colors
        0.0f, 0.0f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
        -1.0f, 0.0f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
        -0.5f,  1.0f, 0.0f,  0.0f, 0.0f, 1.0f    // top
};

//Rectangle vertices --> Tutorial
float vertices[] = {
        0.0f,  0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // top right
        0.0f, -1.0f, 0.0f,  0.0f, 1.0f, 0.0f, // bottom right
        -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, // bottom left
        -1.0f,  0.0f, 0.0f, 1.0f, 1.0f, 1.0f   // top left
};

//Rectangle indexes --> Tutorial
int indices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
};

GLFWwindow * CreateWindow();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void renderLoop(GLFWwindow* window, unsigned int c, Shape* shape[]);