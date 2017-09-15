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
                              int infSize,
                              int sizeNextVertex,
                              int posFirstVertex,
                              int numOfVert){
    vertexArgs va;
    va.inf = inf;
    va.infSize = infSize;
    va.sizeNextVertex = sizeNextVertex;
    va.posFirstVertex = posFirstVertex;
    va.numOfVert = numOfVert;
    return va;
}


texArgs createTexArgs(
                      int sizeNextTex,
                      int posFirstTex,
                      std:: vector<Texture * > text){

    texArgs ta;
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

    Texture * texture = new Texture("assets/container2.png",GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR, GL_TEXTURE0);
    Texture * texture2 = new Texture("assets/container2_specular.png",GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR, GL_TEXTURE1);

    textures.push_back(texture);
    textures.push_back(texture2);

    normalArgs na = createNormalAgrs(3*sizeof(float), 8*sizeof(float));
    vertexArgs va = createVertexArgs(vertices,  sizeof(vertices), 8*sizeof(float),0, 36);
    texArgs ta = createTexArgs(8*sizeof(float), 6*sizeof(float), textures);

    vbo * cube = new vbo(va, ta,na);
    cube->translate(-3.0f,-3.0f,-2.0f);
    vbo * cube2 = new vbo(va, ta,na);
    cube2->rotate(30,true,false,false);
    vbo * cube3 = new vbo(va, ta,na);
    cube3->translate(-2.0f,-2.0f,-3.0f);
    vbo * cube4 = new vbo(va, ta,na);
    cube4->translate(-3.0f,0.0f,-3.0f);
    vbo * cube5 = new vbo(va, ta,na);
    cube5->translate(-4.0f,0.0f,3.0f);
    vbo * cube6 = new vbo(va, ta,na);
    cube6->translate(-5.0f,4.0f,4.0f);
    vbo * cube7 = new vbo(va, ta,na);
    cube7->translate(6.0f,0.0f,0.0f);
    vbo * cube8 = new vbo(va, ta,na);
    cube8->translate(-6.0f,-5.0f,0.0f);

    DirectionalLight* directionalLight = new DirectionalLight(va);
    directionalLight->setDirection(glm::vec3(-0.2f,-1.0f,-0.3f));
    directionalLight->setAmbient(0.05f,0.05f,0.05f);
    directionalLight->setDiffuse(0.4f,0.4f,0.4f);
    directionalLight->setSpecular(0.5f,0.5f,0.5f);

    PointLight * pointLight = new PointLight(va);
    pointLight->translate(3.0f,-3.0f,0.0f);
    pointLight->scale(0.5f,0.5f,0.5f);
    pointLight->setDiffuse(1.0f,0.0f,0.0f);

    SpotLight * spotLight = new SpotLight(va);
    spotLight->translate(0.0f,0.0f,2.0f);
    spotLight->setDirection(glm::vec3(0.0f,0.0f,-1.0f));
    spotLight->scale(0.25f,0.25f,0.25f);

    window.addLight(spotLight);
    window.addLight(directionalLight);
    window.addLight(pointLight);
    window.addShape(cube);
    window.addShape(cube2);
    window.addShape(cube3);
    window.addShape(cube4);
    window.addShape(cube5);
    window.addShape(cube6);
    window.addShape(cube7);
    window.addShape(cube8);

    window.renderLoop();

    glfwTerminate();

    return 0;
}
