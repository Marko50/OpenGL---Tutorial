//
// Created by user on 12-09-2017.
//

#include "DirectionalLight.h"


unsigned int DirectionalLight::count = 0;

void DirectionalLight::updateDirection(const char *dir) {
    std::string direc;
    std::string aux = "dirLight[";
    std::ostringstream ss;
    ss << this->id;
    aux += ss.str();
    aux += "].";
    direc = aux + dir;
    vbo::shader->set3f(direc, this->direction);
}

void DirectionalLight::draw(){
    glUseProgram(vbo::shader->ID);
    this->updateLightProperties("dirLight", "diffuse","specular", "ambient");
    this->updateDirection("direction");

    /*glUseProgram(this->shader->ID);
    this->updateCoordinates("model");
    this->updateNormals("modelChanged");

    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0,this->numOfVert);*/
}