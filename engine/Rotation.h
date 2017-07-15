//
// Created by user on 15-07-2017.
//

#ifndef GAMEENGINE_ROTATION_H
#define GAMEENGINE_ROTATION_H


#include "State.h"

class Rotation : public State {
    bool x;
    bool y;
    bool z;
    float degrees;
public:
    Rotation(const char * u, bool x, bool y, bool z, float degrees);
    void action(unsigned int ID);
};


#endif //GAMEENGINE_ROTATION_H
