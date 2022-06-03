#include "hand.h"
#ifndef Sequence_H
#define Sequence_H
class Sequence{
    public:
    char maior_s;
    char maior;
    std::string sequence;
    Sequence(char maior_,char maior, std::string sequence);
    static Sequence getSequence(Card cards[4]);
};
#endif