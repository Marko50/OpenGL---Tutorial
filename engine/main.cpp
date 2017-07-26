//
// Created by user on 18-07-2017.
//
#include "aux.h"


normalArgs createNormalAgrs(int posFirstNorm, int sizeNextNorm){
    normalArgs na;
    na.posFirstNorm = posFirstNorm;
    na.sizeNextNorm = sizeNextNorm;
    return na;
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
    std::vector<Texture *> textures;
    //Texture * texture = new Texture("assets/container.jpg",GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR, GL_TEXTURE0);
    //Texture * texture2 = new Texture("assets/wall.jpg",GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR, GL_TEXTURE1);
    //textures.push_back(texture);
    //textures.push_back(texture2);
    normalArgs na = createNormalAgrs(3*sizeof(float), 6*sizeof(float));
    vertexArgs va3 = createVertexArgs(vertices3, NULL, sizeof(vertices3), 6*sizeof(float),0, 0, 36);
   // texArgs ta2 = createTexArgs(true, 5*sizeof(float), 3*sizeof(float), textures);
    texArgs ta = createTexArgs(false,0, 0, textures);
    glm::vec4 color(0.0f,1.0f,0.0f,1.0f);
    vbo * cube = new vbo(va3, ta,na, color);
    lightVBO* light = new lightVBO(va3,ta,na,glm::vec3(1.0f));
    light->translate(1.0,1.0,0.4);
    cube->translate(-0.4,0,0);
    window.addShape(cube);
    window.addShape(light);
    window.renderLoop();

     glfwTerminate();

    return 0;

}
