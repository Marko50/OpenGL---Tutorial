//
// Created by user on 22-06-2017.
//

#include "window.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0,0,width,height);
}

Window::Window(int height, int width) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(width,height, "My First Window" , NULL, NULL);
    if(window == NULL){
        std::cout<<"Failed to create GLF window" << std::endl;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        std::cout<<"Failed to initialize GLAD!" << std::endl;
    }
    glEnable(GL_DEPTH_TEST);
    this->camera = new Camera();
}

void Window::processInput() {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE)){
        glfwSetWindowShouldClose(window, true);
    }
}

void Window::renderLoop() {
    while(!glfwWindowShouldClose(window)){
        //input
        this->processInput();
        //render commands
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT);
        shapes[2]->rotate(50*(float)glfwGetTime(),true,false,false);
        for(int i = 0; i < shapes.size(); i ++){
            shapes[i]->draw();
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Window::addShape(Shape *shape) {
    this->shapes.push_back(shape);
}
