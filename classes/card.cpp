#include "card.h"
Card::Card()
{
    value = 0;
    naipe = 'A';
}

Card::Card(short value_, std::string naipe_)
{
    value = value_;
    naipe = naipe_;
}
void Card::setValue(short value_)
{
    value = value_;
}
void Card::setNaipe(std::string naipe_)
{
    naipe = naipe_;
}
