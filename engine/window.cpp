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


void initGLBuffers(unsigned int& VAO, unsigned int& VBO,unsigned int& EBO, float vert[], int size){
    //glGenBuffers(1, &EBO);  RECTANGLE
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glGenBuffers(1, &VBO);
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); RECTANGLE
    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW); RECTANGLE
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, size , vert, GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void *) 0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

int vertexInit(unsigned int& vertexShader, unsigned int& fragmentShader, unsigned int& shaderProgram){
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &firstshadder, NULL);
    glCompileShader(vertexShader);
    int success;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success){
        char infoLog[512];
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        return -1;
    }
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader,1,&secondshader, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success){
        char infoLog[512];
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        return -1;
    }
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram,fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success){
        char infoLog[512];
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        return -1;
    }
    glUseProgram(shaderProgram);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    return 0;
}

void renderLoop(GLFWwindow* window, unsigned int & shaderProgram, unsigned int VAO[], unsigned int EBO[]){
    while(!glfwWindowShouldClose(window)){
        //input
        processInput(window);
        //render commands
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);
        for(int i = 0; i < 2; i ++){
            glBindVertexArray(VAO[i]);
            glDrawArrays(GL_TRIANGLES, 0,3);
        }
        //glBindVertexArray(VAO[0]);
        glDrawArrays(GL_TRIANGLES, 0,3);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}


int main(){
    GLFWwindow* window;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(800,600, "My First Window" , NULL, NULL);
    if(window == NULL){
        std::cout<<"Failed to create GLF window" << std::endl;
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        std::cout<<"Failed to initialize GLAD!" << std::endl;
        return -1;
    }


    unsigned int VAO[2],VBO[2],EBO[2];

    initGLBuffers(VAO[0], VBO[0], EBO[0],vertices3, sizeof(vertices3));
    initGLBuffers(VAO[1], VBO[1], EBO[1],vertices4, sizeof(vertices4));

    unsigned int vertexShader, fragmentShader, shaderProgram;
    if(vertexInit(vertexShader, fragmentShader, shaderProgram) == -1){
        glfwTerminate();
        std::cout << "ERROR::Shaders init failed!" << std::endl;
        return -1;
    }

    renderLoop(window,shaderProgram, VAO,EBO);

    glfwTerminate();
    return 0;
}
