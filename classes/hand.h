#include "card.h"
#ifndef Hand_H
#define Hand_H
class Hand{
    public:
    Card * cards[5];
    Hand(Card * cards_[5]);
    std::string getHand();
};
#endif