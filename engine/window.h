//
// Created by user on 27-06-2017.
//

#include <math.h>
#include "Shape.h"
#include "vbo.h"
#include "ebo.h"
#include "Texture.h"
#include "Camera.h"
#include <iostream>
#include <vector>
#include <GLFW/glfw3native.h>

#ifndef GAMEENGINE_WINDOW_H
#define GAMEENGINE_WINDOW_H

class Window{
private:
    GLFWwindow * window;
    std::vector<Shape *> shapes;
    Camera * camera;
public:
    Window(int height, int width);
    void processInput();
    void renderLoop();
    void addShape(Shape * shape);
    GLFWwindow *getWindow() const {
        return window;
    }
};


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);


#endif //GAMEENGINE_WINDOW_H