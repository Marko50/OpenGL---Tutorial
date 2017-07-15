//
// Created by user on 15-07-2017.
//

#ifndef GAMEENGINE_SCALE_H
#define GAMEENGINE_SCALE_H


#include "State.h"

class Scale : public State {
    float x;
    float y;
    float z;
public:
    Scale(const char * u, float x, float y, float z);
    void action(unsigned int ID);
};


#endif //GAMEENGINE_SCALE_H
