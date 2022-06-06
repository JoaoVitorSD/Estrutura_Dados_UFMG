#include <iostream>
#include "sequence.h"
#include "player.h"
#ifndef Turn_H
#define Turn_H

class Turn{
    public:
    Sequence * sequence;
    Player player;
    int apost;
    Turn(Sequence * sequence_,Player * player_,int apost_);
};
#endif