#include "sequence.h"
Sequence::Sequence(short maior_1_, short maior_2_, short maior_3_, short maior_4_, short maior_5_, std::string sequence_, short sequence_value_)
{
    maior_1 = maior_1_;
    maior_2 = maior_2_;
    maior_3 = maior_3_;
    maior_4 = maior_4_;
    maior_5 = maior_5_;
    sequence = sequence_;
    sequence_value = sequence_value_;
}
Sequence *Sequence::getSequence(Hand *hand)
{
    int i = 0;
    short sequenceByOne = 0;
    bool sequence = false;
    short naipes = 1;
    short equals = 0;
    short diffs = 0;
    short rsf = 0;
    short rs[5] = {10, 11, 12, 13, 14};
    short sato5[5] = {2, 3, 4, 5, 14};
    short sequenceA = 0;
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
        if (hand->cards[i]->naipe.compare(hand->cards[i - 1]->naipe) != 0)
        {
            naipes++;
        }
        if (hand->cards[i]->value - hand->cards[i - 1]->value == 1)
        {
            sequenceByOne++;
        }
    }
    for(i = 0; i < 5; i++){
        if(hand->cards[i]->value==sato5[i]){
            sequenceA++;
        }
        if (hand->cards[i]->value == rs[i])
        {
            rsf++;
        }
    }
    if (sequenceByOne == 4||sequenceA == 5)
    {
        sequence = true;
    }
    if (rsf == 5 && naipes == 1)
    {
        return new Sequence(hand->cards[4]->value, 0, 0, 0, 0, "RSF", 9);
    }
    else if ((sequence) && (naipes == 1))
    {
        if(sequenceA==5){
        return new Sequence(hand->cards[3]->value, 0, 0, 0, 0, "SF", 8);
        }
        return new Sequence(hand->cards[4]->value, 0, 0, 0, 0, "SF", 8);
    }
    else if (diffs == 1)
    {
        if (((hand->cards[3]->value != hand->cards[4]->value) || (hand->cards[0]->value != hand->cards[1]->value) || (hand->cards[1]->value != hand->cards[2]->value)))
        {

            if (hand->cards[3] != hand->cards[4])
            {
                // quadra são as 4 primeiras
                return new Sequence(hand->cards[3]->value, hand->cards[4]->value, 0, 0, 0, "FK", 7);
            }
            // quadra são as 4 últimas
            return new Sequence(hand->cards[3]->value, hand->cards[0]->value, 0, 0, 0, "FK", 7);
        }
    }
    if (diffs == 1)
    {
        if (hand->cards[3] != hand->cards[2])
        {
            return new Sequence(hand->cards[4]->value, hand->cards[2]->value, 0, 0, 0, "FH", 6);
        }
        else{
            return new Sequence(hand->cards[4]->value, hand->cards[1]->value, 0, 0, 0, "FH", 6);
        }
    }
    else if (naipes == 1)
    {
        return new Sequence(hand->cards[4]->value, hand->cards[3]->value, hand->cards[2]->value, hand->cards[1]->value, hand->cards[0]->value, "F", 5);
    }
    else if (sequence)
    {
        if(sequenceA==5){
        return new Sequence(hand->cards[3]->value, 0, 0, 0, 0, "S", 4);
        }
        return new Sequence(hand->cards[4]->value, 0, 0, 0, 0, "S", 4);
    }
    else if (equals == 2)
    {
        if (hand->cards[3]->value != hand->cards[4]->value)
        {
            if (hand->cards[2]->value != hand->cards[3]->value)
            {
                return new Sequence(hand->cards[2]->value, hand->cards[4]->value, hand->cards[3]->value, 0, 0, "TK", 3);
            }
            else if ((hand->cards[2]->value == hand->cards[1]->value) && (hand->cards[2]->value == hand->cards[3]->value))
            {
                return new Sequence(hand->cards[2]->value, hand->cards[4]->value, hand->cards[0]->value, 0, 0, "TK", 3);
            }
        }
        else if ((hand->cards[2]->value == hand->cards[3]->value) && (hand->cards[2]->value == hand->cards[4]->value))
        {
            return new Sequence(hand->cards[4]->value, hand->cards[1]->value, hand->cards[0]->value, 0, 0, "TK", 3);
        }
    }
    if (equals == 2)
    {
        // 2 pares
        if (hand->cards[0]->value != hand->cards[1]->value)
        {
            // todas as duplas estão depois da primeira posição ex: [1,4,4,9,9]
            return new Sequence(hand->cards[4]->value, hand->cards[2]->value, hand->cards[0]->value, 0, 0, "TP", 2);
        }
        else if (hand->cards[1]->value != hand->cards[2]->value)
        {
            // as duplas estão separadas por uma carta ex: [1,1,4,13,13]
            return new Sequence(hand->cards[4]->value, hand->cards[1]->value, hand->cards[2]->value, 0, 0, "TP", 2);
        }
        // as duplas estão no começo
        return new Sequence(hand->cards[3]->value, hand->cards[1]->value, hand->cards[4]->value, 0, 0, "TP", 2);
    }
    else if (equals == 1)
    {

        if (hand->cards[0]->value != hand->cards[1]->value)
        {
            if (hand->cards[1]->value != hand->cards[2]->value)
            {
                if (hand->cards[2]->value == hand->cards[3]->value)
                {
                    return new Sequence(hand->cards[2]->value, hand->cards[4]->value, hand->cards[1]->value, hand->cards[0]->value, 0, "OP", 1);
                }
            }
            else
            {
                return new Sequence(hand->cards[1]->value, hand->cards[4]->value, hand->cards[3]->value, hand->cards[0]->value, 0, "OP", 1);
            }
        }
        return new Sequence(hand->cards[4]->value, hand->cards[2]->value, hand->cards[1]->value, hand->cards[0]->value, 0, "OP", 1);
    }
    else
    {
        return new Sequence(hand->cards[4]->value, hand->cards[3]->value, hand->cards[2]->value, hand->cards[1]->value, hand->cards[0]->value, "HC", 0);
    }
}
int Sequence::isLess(const Sequence *a, const Sequence *b)
{
    if (a->sequence_value < b->sequence_value)
    {
        return 1;
    }
    else if (a->sequence_value == b->sequence_value)
    {
        if (a->maior_1 < b->maior_1)
        {
            return 1;
        }
        else if (a->maior_1 == b->maior_1)
        {
            if (a->maior_2 < b->maior_2)
            {
                return 1;
            }
            else if (a->maior_2 == b->maior_2)
            {
                if (a->maior_3 < b->maior_3)
                {
                    return 1;
                }
                else if (a->maior_3 == b->maior_3)
                {
                    if (a->maior_4 < b->maior_4)
                    {
                        return 1;
                    }
                    else if (a->maior_4 == b->maior_4)
                    {
                        if (a->maior_5 < b->maior_5)
                        {
                            return 1;
                        }
                        else if (a->maior_5 == b->maior_5)
                        {
                            return -1;
                            // empate
                        }
                    }
                }
            }
        }
    }
    return 0;
}