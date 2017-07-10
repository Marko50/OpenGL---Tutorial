//
// Created by user on 09-07-2017.
//

#ifndef GAMEENGINE_TEXTURE_H
#define GAMEENGINE_TEXTURE_H

#include "../deps/glad/glad.h"
#include "stb_image.h"
#include <iostream>





class Texture{
private:
    unsigned int texture;
    int width,height,nrChannels, textureUnit;
public:
    Texture(const char * pathToTexture,int WRAP_S, int WRAP_T, int FILTER_MIN, int FILTER_MAG, int texUnit);
    unsigned int getTexture();
    int getTextureUnit();

};

#endif //GAMEENGINE_TEXTURE_H
