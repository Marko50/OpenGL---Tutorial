//
// Created by user on 15-07-2017.
//

#ifndef GAMEENGINE_STOPPED_H
#define GAMEENGINE_STOPPED_H


#include "State.h"

class Stopped : public State {

public:
    Stopped(const char * u);
    void action(unsigned int ID);

};


#endif //GAMEENGINE_STOPPED_H
