#include "card.h"

#ifndef Player_H
#define Player_H
#define value 50
class Player{
    private:
    std::string name;
    int money = value;

    public:
    Player(std::string name_);
    int getMoney(){return money;};
    std::string getName(){return name;};
};
#endif