//
// Created by user on 25-07-2017.
//

#include "lightVBO.h"

void lightVBO::draw() {
    this->updateTransform("transformTrans","transformRot","transformScale" );
    this->updateCoordinates("model");
    this->updateNormals("modelChanged");
    this->updateMaterial("material.diffuse","material.ambient","material.specular","material.shininess");
    this->updateMaterial("light.diffuse","light.ambient","light.specular","material.shininess");
    this->updateLightPositon("light.position");
    for(unsigned int i = 0; i < this->textures.size(); i++){
        glActiveTexture(this->textures[i]->getTextureUnit());
        glBindTexture(GL_TEXTURE_2D, this->textures[i]->getTexture());
    }
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0,this->numOfVert);
}

void lightVBO::updateLightPositon(const char *uniformLightPos) {
    this->shader->set3f(uniformLightPos, this->x, this->y, this->z);
}

