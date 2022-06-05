#include "hand.h"
#ifndef Sequence_H
#define Sequence_H
class Sequence
{
public:
    short maior_s;
    short maior;
    std::string sequence;
    short sequence_value;
    Sequence(){};
    Sequence(short maior_s_, short maior_, std::string sequence_, short sequence_value_);
    static Sequence getSequence(Hand hand);
    static int isLess(const Sequence * a, const Sequence * sequence);
};
#endif