#include "hand.h"

Hand::Hand(Card *cards_[5])
{
    int i = 0, j = 0;
    Card *aux = new Card();
    cards[0] = new Card(cards_[0]->getValue(), cards_[0]->getNaipe());
    cards[1] = new Card(cards_[1]->getValue(), cards_[1]->getNaipe());
    cards[2] = new Card(cards_[2]->getValue(), cards_[2]->getNaipe());
    cards[3] = new Card(cards_[3]->getValue(), cards_[3]->getNaipe());
    cards[4] = new Card(cards_[4]->getValue(), cards_[4]->getNaipe());
    for (i = 0; i < 5; i++)
    {
        for (j = 1; j < 5 - i; j++)
        {
            if (cards[j]->value < cards[j - 1]->value)
            {
                aux->value = cards[j - 1]->value;
                aux->naipe.assign(cards[j - 1]->naipe);
                cards[j - 1]->value = cards[j]->value;
                cards[j - 1]->naipe.assign(cards[j]->naipe);
                cards[j]->value = aux->value;
                cards[j]->naipe.assign(aux->naipe);
            }
        }
    }
}

std::string Hand::getHand()
{
    std::string hand = "";
    for (int i = 0; i < 5; i++)
    {
        hand += " " + cards[i]->getCard();
    }
    return hand;
}