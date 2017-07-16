//
// Created by user on 15-07-2017.
//

#ifndef GAMEENGINE_TRANSLATION_H
#define GAMEENGINE_TRANSLATION_H


#include "State.h"

class Translation : public State {
    float x;
    float y;
    float z;
public:
    Translation(const char * u, float x, float y, float z);
    void action(unsigned int ID);
};


#endif //GAMEENGINE_TRANSLATION_H
