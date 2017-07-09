//
// Created by user on 09-07-2017.
//

#ifndef GAMEENGINE_TEXTURE_H
#define GAMEENGINE_TEXTURE_H

#include "window.h"

class Texture{
private:
    int texture,width,height,nrChannels;
    unsigned  char * data;
public:
    Texture();

};

#endif //GAMEENGINE_TEXTURE_H
