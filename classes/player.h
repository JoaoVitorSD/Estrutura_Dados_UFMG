#include "sequence.h"

#ifndef Player_H
#define Player_H

class Player{
    public: 
    std::string name;
    int money;
    Player(){};
    Player(std::string name_,int initialMoney);
    int getMoney(){return money;};
    std::string getName(){return name;};
};
#endif