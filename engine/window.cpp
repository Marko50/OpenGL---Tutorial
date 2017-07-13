//
// Created by user on 22-06-2017.
//

#include "window.h"

shaderArgs createShaderArgs(int lposVer, int lPosColor, int lPosTex){
    shaderArgs sa;
    sa.layoutLocationVertex = lposVer;
    sa.layoutLocationColor = lPosColor;
    sa.layoutLocationTex = lPosTex;
    return  sa;
}

vertexArgs createVertexArgs(  float * inf,
                              int * ind,
                              int infSize,
                              int sizeNextVertex,
                              int posFirstVertex,
                              int indSize){
    vertexArgs va;
    va.inf = inf;
    va.ind = ind;
    va.infSize = infSize;
    va.sizeNextVertex = sizeNextVertex;
    va.posFirstVertex = posFirstVertex;
    va.indSize = indSize;

    return va;
}

colArgs createColorArgs( bool col,
                         int sizeNextColor,
                         int posFirstColor){
    colArgs ca;
    ca.col = col;
    ca.sizeNextColor = sizeNextColor;
    ca.posFirstColor = posFirstColor;
    return ca;
}

texArgs createTexArgs(bool tex,
                      int sizeNextTex,
                      int posFirstTex,
                      std:: vector<Texture * > text){

    texArgs ta;
    ta.tex = tex;
    ta.sizeNextTex = sizeNextTex;
    ta.posFirstTex = posFirstTex;
    ta.text = text;

    return ta;
}

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
    unsigned  int numOfShapes = 2;
    shaderArgs sa = createShaderArgs(0,1,2);
    Shader * shader = new Shader("files/vertexShader", "files/fragmentShader",sa);
    Shader * shader2 = new Shader("files/vertexShader", "files/fragmentShader", sa);
    std::vector<Texture *> textures;
    Texture * texture = new Texture("assets/container.jpg",GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR, GL_TEXTURE0);
    Texture * texture2 = new Texture("assets/wall.jpg",GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR, GL_TEXTURE1);
    textures.push_back(texture);
    textures.push_back(texture2);
    texArgs ta = createTexArgs(true, 8*sizeof(float), 6*sizeof(float),textures);
    colArgs ca = createColorArgs(true,8*sizeof(float),3*sizeof(float));
    vertexArgs va = createVertexArgs(vertices2,indices,sizeof(vertices2),8*sizeof(float),0,sizeof(indices));
    vertexArgs va2 = createVertexArgs(vertices1, NULL , sizeof(vertices1), 8*sizeof(float), 0, 0);
    Triangle* triangle = new Triangle(va2,ca,ta,shader2);
    Rectangle * rectangle= new Rectangle(va,ca,ta,shader);
    Shape* shapes[numOfShapes] = {rectangle,triangle};
    renderLoop(window,numOfShapes,shapes);
    glfwTerminate();
    return 0;
}
