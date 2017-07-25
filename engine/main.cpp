//
// Created by user on 18-07-2017.
//
#include "aux.h"


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
                              int indSize,
                              int numOfVert){
    vertexArgs va;
    va.inf = inf;
    va.ind = ind;
    va.infSize = infSize;
    va.sizeNextVertex = sizeNextVertex;
    va.posFirstVertex = posFirstVertex;
    va.indSize = indSize;
    va.numOfVert = numOfVert;
    return va;
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



int main(){
    Window window = Window(600,800);
    if(window.getWindow() == NULL){
        std::cout<<"Failed to create GLF window" << std::endl;
        return -1;
    }
    shaderArgs sa = createShaderArgs(0,1,2);
    Shader * shader = new Shader("files/vertexShader", "files/fragmentShader",sa);
    std::vector<Texture *> textures;
    Texture * texture = new Texture("assets/container.jpg",GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR, GL_TEXTURE0);
    Texture * texture2 = new Texture("assets/wall.jpg",GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR, GL_TEXTURE1);
    textures.push_back(texture);
    textures.push_back(texture2);
    texArgs ta = createTexArgs(true, 8*sizeof(float), 6*sizeof(float),textures);
    vertexArgs va = createVertexArgs(vertices2,indices,sizeof(vertices2),8*sizeof(float),0,sizeof(indices),6);
    vertexArgs va2 = createVertexArgs(vertices1, NULL , sizeof(vertices1), 8*sizeof(float), 0, 0,3);
    vertexArgs va3 = createVertexArgs(vertices, NULL, sizeof(vertices), 5*sizeof(float),0, 0, 36);
    texArgs ta2 = createTexArgs(true, 5*sizeof(float), 3*sizeof(float), textures);
    glm::vec4 color(0.0f,1.0f,0.0f,1.0f);
    vbo * cube = new vbo(va3, ta2, shader,color);
    lightVBO* light = new lightVBO(va3,ta2,shader, glm::vec3(1.0f));
    light->translate(1.0,0,0);
    cube->translate(-0.4,0,0);
   // vbo* triangle = new vbo(va2,ta,shader,color);
    //triangle->scale(2.0,0.5,1.0);
    //ebo * rectangle= new ebo(va,ta,shader,color);
    window.addShape(cube);
    window.addShape(light);
    //window.addShape(triangle);
    //window.addShape(rectangle);
    window.renderLoop();
    glfwTerminate();
    return 0;
}