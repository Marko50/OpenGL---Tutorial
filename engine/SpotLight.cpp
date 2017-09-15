//
// Created by user on 12-09-2017.
//

#include "SpotLight.h"


unsigned int SpotLight::count = 0;

void SpotLight::draw() {
    glUseProgram(vbo::shader->ID);
    this->updateLightProperties("spotLight", "diffuse","specular", "ambient");
    this->updateAngles("cutOff", "outerCutOff", "constant", "linear", "quadratic");
    this->updateDirection("direction");
    this->updatePosition("position");

    glUseProgram(this->shader->ID);
    this->updateTransform("transformTrans","transformRot","transformScale" );
    this->updateCoordinates("model");
    this->updateNormals("modelChanged");

    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0,this->numOfVert);
}

void SpotLight::updateAngles(const char *cutOff, const char *outerCutOff, const char *constant, const char *linear,
                             const char *quadratic) {
    std::string c,o,cons,lin,quad;
    std::string aux = "spotLight[";
    std::ostringstream ss;
    ss << this->id;
    aux += ss.str();
    aux += "].";
    c = aux + cutOff;
    o = aux + outerCutOff;
    cons = aux + constant;
    lin = aux + linear;
    quad = aux + quadratic;
    vbo::shader->setFloat(c, this->cutOff);
    vbo::shader->setFloat(o, this->outerCutOff);
    vbo::shader->setFloat(cons, this->constant);
    vbo::shader->setFloat(lin, this->linear);
    vbo::shader->setFloat(quad, this->quadratic);
}

void SpotLight::updateDirection(const char *dir) {
    std::string direc;
    std::string aux = "spotLight[";
    std::ostringstream ss;
    ss << this->id;
    aux += ss.str();
    aux += "].";
    direc = aux + dir;
    vbo::shader->set3f(direc, this->direction);
}

void SpotLight::updatePosition(const char *pos) {
    std::string posit;
    std::string aux = "spotLight[";
    std::ostringstream ss;
    ss << this->id;
    aux += ss.str();
    aux += "].";
    posit = aux + pos;

    vbo::shader->set3f(posit, this->x, this->y, this->z);
}