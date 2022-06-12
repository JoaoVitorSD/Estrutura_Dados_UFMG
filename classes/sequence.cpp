#include "sequence.h"
Sequence::Sequence(short maior_s_, short maior_, std::string sequence_, short sequence_value_)
{
    maior_s = maior_s_;
    maior = maior_;
    sequence = sequence_;
    sequence_value = sequence_value_;
}
Sequence * Sequence::getSequence(Hand * hand)
{
    int i = 0;
    short sequenceByOne = 0;
    bool sequence = false;
    short naipes = 1;
    short equals = 0;
    short diffs = 0;
    short rsf = 0;
    short rs[5]={1,10,11,11,13};
     if(hand->cards[0]->value==rs[0]){
            rsf++;
        }
    for (i = 1; i < 5; i++)
    {
        if (hand->cards[i]->value == hand->cards[i - 1]->value)
        {
            equals++;
        }
        else
        {
            diffs++;
        }
        if (hand->cards[i]->naipe.compare(hand->cards[i - 1]->naipe)!=0)
        {
            naipes++;
        }
        if (hand->cards[i]->value - hand->cards[i - 1]->value == 1)
        {
            sequenceByOne++;
        }
        if(hand->cards[i]->value==rs[i]){
            rsf++;
        }
    }
    if (sequenceByOne == 4)
    {
        sequence = true;
    }
    if (rsf==4&&naipes==1)
    {
        return new  Sequence(hand->cards[4]->value, 0, "RSF",9);
    }
    else if ((sequence) && (naipes == 1))
    {
        return new  Sequence(hand->cards[4]->value, 0, "SF",8);
    }
    else if (diffs == 1 && (hand->cards[3] != hand->cards[4] ^ hand->cards[0] != hand->cards[1]))
    {
        std::cout<<hand->getHand();
        if (hand->cards[3] != hand->cards[4])
        {
            return new  Sequence(hand->cards[3]->value, hand->cards[4]->value, "FK",7);
        }
        return new  Sequence(hand->cards[3]->value, hand->cards[0]->value, "FK",7);
    }
    else if (diffs == 1)
    {
        return new  Sequence(hand->cards[4]->value, 0, "FH",6);
    }
    else if (naipes == 1)
    {
        return new  Sequence(hand->cards[4]->value, 0, "F",5);
    }
    else if (sequence)
    {
        return new  Sequence(hand->cards[4]->value, 0, "S",4);
    }
    else if (equals == 2 && (hand->cards[1]->value == hand->cards[2]->value || hand->cards[2]->value == hand->cards[3]->value))
    {
        if (hand->cards[3]->value != hand->cards[4]->value)
        {
            return new  Sequence(hand->cards[2]->value, hand->cards[4]->value, "TK",3);
        }
        return new  Sequence(hand->cards[2]->value, hand->cards[0]->value, "TK",3);
    }
    else if (equals == 2)
    {
        if (hand->cards[0]->value != hand->cards[1]->value)
        {
            return new  Sequence(hand->cards[4]->value, hand->cards[0]->value, "TP",2);
        }
        else if(hand->cards[1]->value != hand->cards[2]->value){
            return new  Sequence(hand->cards[4]->value, hand->cards[2]->value, "TP",2);
        }
        return new  Sequence(hand->cards[3]->value, hand->cards[4]->value, "TP",2);
    }
    else if (equals == 1)
    {
        for (i = 1; i < 5; i++)
        {
            if (i < 4)
            {
                if (hand->cards[i]->value == hand->cards[i - 1]->value)
                {
                    return new  Sequence(hand->cards[i]->value, hand->cards[4]->value, "OP",1);
                }
            }
        }
        return new  Sequence(hand->cards[4]->getValue(), hand->cards[2]->getValue(), "OP",1);
    }
    else
    {
        return new Sequence(hand->cards[4]->getValue(), hand->cards[3]->getValue(), "HC",0);
    }
}
int Sequence::isLess(const Sequence * a, const Sequence *b)
    {
        if (a->sequence_value < b->sequence_value)
        {
            return 1;
        }
        else if (a->sequence_value == b->sequence_value)
        {
            if (a->maior_s < b->maior_s)
            {
                return 1;
            }
            else if (a->maior_s == b->maior_s)
            {
                if (a->maior < b->maior)
                {
                    return 1;
                }
                else if (a->maior == b->maior)
                {
                    return -1;
                    // empate;
                }
            }
        }
        return 0;
    }