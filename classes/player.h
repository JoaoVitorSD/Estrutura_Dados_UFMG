#include "card.h"

#ifndef Player_H
#define Player_H

class Player{
    private:
    std::string name;
    int money;

    public:
    Player();
    Player(std::string name_,int initialMoney);
    int getMoney(){return money;};
    std::string getName(){return name;};
};
#endif