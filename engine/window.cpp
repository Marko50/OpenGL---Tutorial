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
    //position
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void *) 0);
    glEnableVertexAttribArray(0);
    //color
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

int vertexInit(unsigned int& vertexShader, unsigned int& fragmentShader, unsigned int& shaderProgram, int shad){
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vshader, NULL);
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
    if(shad == 1)
        glShaderSource(fragmentShader,1,&fshader, NULL);
    else if (shad == 2)
        glShaderSource(fragmentShader,1,&fshaderb, NULL);

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

void renderLoop(GLFWwindow* window, unsigned int  shaderProgram[], unsigned int VAO[], unsigned int EBO[], unsigned int c){
    while(!glfwWindowShouldClose(window)){
        //input
        processInput(window);
        //render commands
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
       // float timeValue = glfwGetTime();
        //float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
        for(int i = 0; i < c; i ++){
           int vertexColorLocation = glGetUniformLocation( shaderProgram[i],"ourColor");
           // glUseProgram(shaderProgram[i]);
            //if(vertexColorLocation != -1){
              //  glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
            //}
            glBindVertexArray(VAO[i]);
            glDrawArrays(GL_TRIANGLES, 0,3);
        }
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

    int nrAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;
    unsigned int VAO[2],VBO[2],EBO[2];

    initGLBuffers(VAO[0], VBO[0], EBO[0],vertices5, sizeof(vertices5));
    //initGLBuffers(VAO[1], VBO[1], EBO[1],vertices5, sizeof(vertices5));

    unsigned int vertexShader, fragmentShader, shaderProgram[2];
    if(vertexInit(vertexShader, fragmentShader, shaderProgram[0],1) == -1){
        glfwTerminate();
        std::cout << "ERROR::Shaders init failed!" << std::endl;
        return -1;
    }
    if(vertexInit(vertexShader, fragmentShader, shaderProgram[1],2) == -1){
        glfwTerminate();
        std::cout << "ERROR::Shaders init failed! 2" << std::endl;
        return -1;
    }

    renderLoop(window,shaderProgram, VAO,EBO,1);

    glfwTerminate();
    return 0;
}
