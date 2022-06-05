#include "hand.h"

Hand::Hand(Card **cards_)
{
    int i = 0, j = 0;
    Card * aux;
    for (i = 0; i < 5; i++)
    {
        cards[i] = cards_[i];
    }
    for (i = 0; i < 5; i++)
    {
        for (j = 1; j < 5 - i; j++)
        {
            if (cards[j] < cards[j - 1])
            {
                aux = cards[j - 1];
                cards[j - 1] = cards[j];
                cards[j] = aux;
            }
        }
    }
}

std::string Hand::getHand()
{
    std::string hand = "";
    for (int i = 0; i < 5; i++)
    {
        hand += " "+cards[i]->getCard();
    }
    return hand;
}