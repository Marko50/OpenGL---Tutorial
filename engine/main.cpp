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
    std::vector<Texture *> textures2;
    //Texture * texture1 = new Texture("assets/2560x1440-white-solid-color-background.jpg",GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR, GL_TEXTURE0);
    Texture * texture = new Texture("assets/container2.png",GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR, GL_TEXTURE0);
    Texture * texture2 = new Texture("assets/container2_specular.png",GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR, GL_TEXTURE1);

    textures.push_back(texture);
    textures.push_back(texture2);

    normalArgs na = createNormalAgrs(3*sizeof(float), 8*sizeof(float));
    vertexArgs va3 = createVertexArgs(vertices, NULL, sizeof(vertices), 8*sizeof(float),0, 0, 36);
    texArgs ta2 = createTexArgs(true, 8*sizeof(float), 6*sizeof(float), textures);
    texArgs ta = createTexArgs(false,0, 0, textures2);
    vbo * cube = new vbo(va3, ta2,na);
    cube->translate(-1.0f,0.0f,0.0f);
    vbo * cube2 = new vbo(va3, ta2,na);
    //cube2->translate(2,3,2);

    DirectionalLight* directionalLight = new DirectionalLight(va3,ta,na);
    directionalLight->setDirection(glm::vec3(-0.2f,-1.0f,-0.3f));
    directionalLight->setAmbient(0.05f,0.05f,0.05f);
    directionalLight->setDiffuse(0.4f,0.4f,0.4f);
    directionalLight->setSpecular(0.5f,0.5f,0.5f);
    PointLight * pointLight = new PointLight(va3, ta , na);
    pointLight->scale(0.5f,0.5f,0.5f);
    pointLight->translate(2.0f,1.0f,3.0f);
    SpotLight * spotLight = new SpotLight(va3,ta,na);
   // spotLight->translate(window.getCamera()->Position.x, window.getCamera()->Position.y, window.getCamera()->Position.z);
    //spotLight->setDirection(window.getCamera()->Front);
    spotLight->translate(2.0f,0.0f,0.0f);
    spotLight->setDirection(glm::vec3(-1.0f,0.0f,0.0f));
    spotLight->scale(0.25f,0.25f,0.25f);

    window.addLight(spotLight);
    window.addLight(directionalLight);
    //window.addLight(pointLight);
    window.addShape(cube);
    //window.addShape(cube2);
    window.renderLoop();
    glfwTerminate();
    return 0;
}
