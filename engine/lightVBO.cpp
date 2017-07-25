//
// Created by user on 25-07-2017.
//

#include "lightVBO.h"

void lightVBO::draw() {
    this->updateTransform("transformTrans","transformRot","transformScale" );
    this->updateCoordinates("model");
    this->updateColor("color");
    this->updateLightColor("lightColor");
    this->setAmbient("ambientStrength");
    for(unsigned int i = 0; i < this->textures.size(); i++){
        glActiveTexture(this->textures[i]->getTextureUnit());
        glBindTexture(GL_TEXTURE_2D, this->textures[i]->getTexture());
    }
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0,this->numOfVert);
}

void lightVBO::updateLightColor(const char *uniformLight) {
    this->shader->set4f(uniformLight, this->lightColor.x, this->lightColor.y, this->color.z, 1.0);
}


void lightVBO::changeLightColor(float R, float G, float B) {
    this->lightColor.x = R;
    this->lightColor.y = G;
    this->lightColor.z = B;
}

void lightVBO::setAmbient(const char * uniformAmbient) {
    this->shader->setFloat(uniformAmbient, 1.0f);
}