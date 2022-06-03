#include "card.h"
#ifndef Hand_H
#define Hand_H
class Hand{
    public:
    Card cards[4];
    Hand(Card cards_[4]);
    std::string getHand();
    Card * getCards(){return cards;}
};
#endif