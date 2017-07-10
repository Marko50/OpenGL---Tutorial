//
// Created by user on 22-06-2017.
//

#include "window.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0,0,width,height);
}

void processInput(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE)){
        glfwSetWindowShouldClose(window, true);
    }
}

void renderLoop(GLFWwindow* window, unsigned int c, Shape* shapes[]){
    while(!glfwWindowShouldClose(window)){
        //input
        processInput(window);
        //render commands
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        for(int i = 0; i < c; i ++){
            shapes[i]->draw();
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

GLFWwindow * CreateWindow(){
    GLFWwindow* window;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(800,600, "My First Window" , NULL, NULL);
    if(window == NULL){
        std::cout<<"Failed to create GLF window" << std::endl;
        return NULL;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        std::cout<<"Failed to initialize GLAD!" << std::endl;
        return NULL;
    }
    return window;
}


int main(){
    GLFWwindow* window = CreateWindow();
    if(window == NULL){
        std::cout<<"Failed to create GLF window" << std::endl;
        return -1;
    }
    unsigned  int numOfShapes = 1;
    Shader * shader = new Shader("files/vertexShader", "files/fragmentShader");
    std::vector<Texture *> textures;
    std::vector<int> tCount;
    std::vector<const char *> uniformNames;
    Texture * texture = new Texture("assets/container.jpg",GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR, GL_TEXTURE0);
    //Texture * texture2 = new Texture("assets/awesomeface.png",GL_REPEAT,GL_REPEAT, GL_LINEAR, GL_LINEAR, GL_TEXTURE1);
    textures.push_back(texture);
    //textures.push_back(texture2);
    tCount.push_back(0);
    //tCount.push_back(1);
    uniformNames.push_back("ourTexture1");
    //uniformNames.push_back("ourTexture2");
    Rectangle * rectangle= new Rectangle(true, true, vertices2,indices, sizeof(vertices2), 8 * sizeof(float), 0, 8 * sizeof(float), 3 * sizeof(float), 8 * sizeof(float), 6 * sizeof(float), 0, 1, 2, shader, textures, tCount , uniformNames);
    Shape* shapes[numOfShapes] = {rectangle};
    renderLoop(window,numOfShapes,shapes);
    glfwTerminate();
    return 0;
}
