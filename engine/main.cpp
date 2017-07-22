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
    colArgs ca = createColorArgs(true,8*sizeof(float),3*sizeof(float));
    colArgs ca2 = createColorArgs(false, 0,0);
    vertexArgs va = createVertexArgs(vertices2,indices,sizeof(vertices2),8*sizeof(float),0,sizeof(indices),6);
    vertexArgs va2 = createVertexArgs(vertices1, NULL , sizeof(vertices1), 8*sizeof(float), 0, 0,3);
    vertexArgs va3 = createVertexArgs(vertices, NULL, sizeof(vertices), 5*sizeof(float),0, 0, 36);
    texArgs ta2 = createTexArgs(true, 5*sizeof(float), 3*sizeof(float), textures);
    vbo * cube = new vbo(va3, ca2, ta2, shader);
    cube->translate(-0.4,0,0);
    vbo* triangle = new vbo(va2,ca,ta,shader);
    triangle->scale(2.0,0.5,1.0);
    ebo * rectangle= new ebo(va,ca,ta,shader);
    window.addShape(cube);
    window.addShape(triangle);
    window.addShape(rectangle);
    window.renderLoop();
    glfwTerminate();
    return 0;
}