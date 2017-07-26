//
// Created by user on 22-06-2017.
//

#include "window.h"

float deltaTime = 0.0f;
float lastFrame = 0.0f;

float xoffset = 0.0f;
float yoffset = 0.0f;

float yScroll = 0.0f;

float lastX = 800 / 2.0f;
float lastY = 600 / 2.0f;

bool firstMouse = true;

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    yScroll = yoffset;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0,0,width,height);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos){
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    xoffset = xpos - lastX;
    yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;
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
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        std::cout<<"Failed to initialize GLAD!" << std::endl;
    }
    glEnable(GL_DEPTH_TEST);
    this->camera = new Camera(glm::vec3(0.0f, 0.0f, 3.0f));
}

void Window::processInput() {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE)){
        glfwSetWindowShouldClose(window, true);
    }
    else if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        this->camera->ProcessKeyboard(FORWARD, deltaTime);
    else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        this->camera->ProcessKeyboard(BACKWARD, deltaTime);
    else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        this->camera->ProcessKeyboard(LEFT, deltaTime);
    else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        this->camera->ProcessKeyboard(RIGHT, deltaTime);
}

void Window::renderLoop() {
    glUseProgram(Shape::shader->ID);
    while(!glfwWindowShouldClose(window)){
        float currentFrame = (float)glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        //input
        this->processInput();
        //render commands
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT);
        this->camera->ProcessMouseMovement(xoffset,yoffset);
        this->camera->ProcessMouseScroll(yScroll);
        for(int i = 0; i < shapes.size(); i ++){
            this->camera->update(shapes[i]->shader->ID, "view", "projection");
            shapes[i]->draw();
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Window::addShape(Shape *shape) {
    this->shapes.push_back(shape);
}
