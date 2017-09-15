//
// Created by user on 12-09-2017.
//

#include "PointLight.h"

unsigned int PointLight::count = 0;

void PointLight::draw() {
    glUseProgram(vbo::shader->ID);
    this->updateLightProperties("pointLight", "diffuse","specular", "ambient");
    this->updatePosition("position");
    this->updateAttenuation("constant", "linear", "quadratic");

    glUseProgram(this->shader->ID);
    this->updateTransform("transformTrans","transformRot","transformScale" );
    this->updateCoordinates("model");
    this->updateNormals("modelChanged");

    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0,this->numOfVert);
}

void PointLight::updatePosition(const char *pos) {
    std::string posit;
    std::string aux = "pointLight[";
    std::ostringstream ss;
    ss << this->id;
    aux += ss.str();
    aux += "].";
    posit = aux + pos;
    vbo::shader->set3f(posit, this->x, this->y, this->z);
}

void PointLight::updateAttenuation(const char *constant, const char *linear, const char *quadratic) {
    std::string cons,lin,quad;
    std::string aux = "pointLight[";
    std::ostringstream ss;
    ss << this->id;
    aux += ss.str();
    aux += "].";

    cons = aux + constant;
    lin = aux + linear;
    quad = aux + quadratic;
    vbo::shader->setFloat(cons, this->constant);
    vbo::shader->setFloat(lin, this->linear);
    vbo::shader->setFloat(quad, this->quadratic);
}