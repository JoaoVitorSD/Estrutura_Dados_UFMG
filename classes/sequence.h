#include "hand.h"
#ifndef Sequence_H
#define Sequence_H
class Sequence
{
public:
    short sequence_value;
    short maior_1;
    short maior_2;
    short maior_3;
    short maior_4;
    short maior_5;
    std::string sequence;
    Sequence(){};
    Sequence(short maior_1_,short maior_2_,short maior_3_, short maior_4_,short maior_5_, std::string sequence_, short sequence_value_);
    static Sequence * getSequence(Hand * hand);
    static int isLess(const Sequence * a, const Sequence * sequence);
};
#endif