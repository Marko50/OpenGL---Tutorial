//
// Created by user on 27-06-2017.
//

#include <math.h>
#include "Shape.h"
#include "vbo.h"
#include "lightVBO.h"
#include "Texture.h"
#include "Camera.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"
#include <iostream>
#include <vector>
#include <GLFW/glfw3native.h>

#ifndef GAMEENGINE_WINDOW_H
#define GAMEENGINE_WINDOW_H

class Window{
private:
    GLFWwindow * window;
    std::vector<vbo *> shapes;
    std::vector <lightVBO *> lights;
public:
    Camera *getCamera() const {
        return camera;
    }

private:
    Camera * camera;
public:
    Window(int height, int width);
    void processInput();
    void renderLoop();
    void addShape(vbo * shape);
    void addLight(lightVBO * light);
    GLFWwindow *getWindow() const {
        return window;
    }
};


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);


#endif //GAMEENGINE_WINDOW_H