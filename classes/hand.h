#include "card.h"
#ifndef Hand_H
#define Hand_H
class Hand{
    public:
    Card **cards;
    Hand(Card ** cards_);
    std::string getHand();
    Card ** getCards(){return cards;}
};
#endif