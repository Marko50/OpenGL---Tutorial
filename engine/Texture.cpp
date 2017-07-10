//
// Created by user on 09-07-2017.
//

#include "Texture.h"

Texture::Texture(const char *pathToTexture, int WRAP_S, int WRAP_T, int FILTER_MIN, int FILTER_MAG, int texUnit) {
    this->textureUnit = texUnit;
    glGenTextures(1 ,&this->texture);
    glBindTexture(GL_TEXTURE_2D,this->texture);

    //set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, WRAP_S);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, WRAP_T);
    if(WRAP_S == GL_CLAMP_TO_BORDER || WRAP_T == GL_CLAMP_TO_BORDER){
        float borderColor[] = { 1.0f, 1.0f, 0.0f, 1.0f };
        glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    }
    //set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, FILTER_MIN);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, FILTER_MAG);

    // load image, create texture and generate mipmaps
    unsigned  char * data = stbi_load(pathToTexture, &width, &height, &nrChannels, 0);
    if(data){
        glTexImage2D(GL_TEXTURE_2D, 0 , GL_RGB , width , height , 0, GL_RGB , GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else{
        std::cout << "FAILED TO LOAD TEXTURE" << std::endl;
    }
    stbi_image_free(data);
}

unsigned int Texture::getTexture() {
    return this->texture;
}
int Texture::getTextureUnit() {
    return this->textureUnit;
}