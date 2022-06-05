#include "sequence.h"
Sequence::Sequence(short maior_s_, short maior_, std::string sequence_, short sequence_value_)
{
    maior_s = maior_s_;
    maior = maior_;
    sequence = sequence_;
    sequence_value = sequence_value_;
}
Sequence Sequence::getSequence(Hand hand)
{
    int i = 0;
    char sequenceByOne = 0;
    bool sequence = false;
    char naipes = 1;
    char equals = 0;
    char diffs = 0;
    for (i = 1; i < 5; i++)
    {
        if (hand.cards[i] == hand.cards[i - 1])
        {
            equals++;
        }
        else
        {
            diffs++;
        }
        if (hand.cards[i]->getNaipe() != hand.cards[i - 1]->getNaipe())
        {
            naipes++;
        }
        if (hand.cards[i]->getValue() - hand.cards[i - 1]->getValue() == 1||(hand.cards[0]->getValue()==1&&hand.cards[1]->getValue()==10))
        {
            sequenceByOne++;
        }
    }
    if (sequenceByOne == 4)
    {
        sequence = true;
    }
    if ((sequence) && (hand.cards[0]->getValue() == 10) && (naipes == 1))
    {
        return  Sequence(hand.cards[4]->getValue(), 0, "RSF",9);
    }
    else if ((sequence) && (naipes == 1))
    {
        return  Sequence(hand.cards[4]->getValue(), 0, "SF",8);
    }
    else if (diffs == 1 && (hand.cards[3] != hand.cards[4] ^ hand.cards[0] != hand.cards[1]))
    {
        std::cout<<hand.getHand();
        if (hand.cards[3] != hand.cards[4])
        {
            return  Sequence(hand.cards[3]->getValue(), hand.cards[4]->getValue(), "FK",7);
        }
        return  Sequence(hand.cards[3]->getValue(), hand.cards[0]->getValue(), "FK",7);
    }
    else if (diffs == 1)
    {
        return  Sequence(hand.cards[4]->getValue(), 0, "FH",6);
    }
    else if (naipes == 1)
    {
        return  Sequence(hand.cards[4]->getValue(), 0, "F",5);
    }
    else if (sequence)
    {
        return  Sequence(hand.cards[4]->getValue(), 0, "S",4);
    }
    else if (equals == 2 && (hand.cards[1] == hand.cards[2] || hand.cards[2] == hand.cards[3]))
    {
        if (hand.cards[3] != hand.cards[4])
        {
            return  Sequence(hand.cards[2]->getValue(), hand.cards[4]->getValue(), "TK",3);
        }
        return  Sequence(hand.cards[2]->getValue(), hand.cards[0]->getValue(), "TK",3);
    }
    else if (equals == 2)
    {
        if (hand.cards[0] != hand.cards[1])
        {
            return  Sequence(hand.cards[4]->getValue(), hand.cards[0]->getValue(), "TP",2);
        }
        return  Sequence(hand.cards[3]->getValue(), hand.cards[4]->getValue(), "TP",2);
    }
    else if (equals == 1)
    {
        for (i = 1; i < 5; i++)
        {
            if (i < 4)
            {
                if (hand.cards[i] == hand.cards[i - 1])
                {
                    return  Sequence(hand.cards[i]->getValue(), hand.cards[4]->getValue(), "OP",1);
                }
            }
        }
        return  Sequence(hand.cards[4]->getValue(), hand.cards[2]->getValue(), "OP",1);
    }
    else
    {
        return Sequence(hand.cards[4]->getValue(), hand.cards[4]->getValue(), "HC",0);
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