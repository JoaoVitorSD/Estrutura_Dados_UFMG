#include "sequence.h"
Sequence::Sequence(char maior_s_, char maior_, std::string sequence_)
{
    maior_s = maior_s_;
    maior = maior_;
    sequence = sequence_;
}
Sequence Sequence::getSequence(Card cards[4])
{
    int i = 0;
    char sequenceByOne = 0;
    bool sequence = false;
    char naipes = 1;
    char equals = 0;
    char diffs = 0;
    for (i = 1; i < 5; i++)
    {
        if (cards[i] == cards[i - 1])
        {
            equals++;
        }
        else
        {
            diffs++;
        }
        if (cards[i].getNaipe() != cards[i - 1].getNaipe())
        {
            naipes++;
        }
        if (cards[i].getValue() - cards[i - 1].getValue() == 1)
        {
            sequenceByOne++;
        }
    }
    if (sequenceByOne == 4)
    {
        sequence = true;
    }
    if ((sequence) && (cards[0].getValue() == 9) && (naipes == 1))
    {
        return Sequence(cards[4].getValue(), 0, "FK");
    }
    else if ((sequence) && (naipes == 1))
    {
        return Sequence(cards[4].getValue(), 0, "SF");
    }
    else if (diffs == 1 && (cards[3] != cards[4] ^ cards[0] != cards[1]))
    {
        if (cards[3] != cards[4])
        {
            return Sequence(cards[3].getValue(), cards[4].getValue(), "FK");
        }
        return Sequence(cards[3].getValue(), cards[0].getValue(), "FK");
    }
    else if (diffs == 1)
    {
        return Sequence(cards[4].getValue(), 0, "FH");
    }
    else if (naipes == 1)
    {
        return Sequence(cards[4].getValue(), 0, "F");
    }
    else if (sequence)
    {
        return Sequence(cards[4].getValue(), 0, "S");
    }
    else if (equals == 2 && (cards[1] == cards[2] || cards[2] == cards[3]))
    {
        if (cards[3] != cards[4])
        {
            return Sequence(cards[2].getValue(), cards[4].getValue(), "TK");
        }
        return Sequence(cards[2].getValue(), cards[0].getValue(), "TK");
    }
    else if (equals == 2)
    {
        if (cards[0] != cards[1])
        {
            return Sequence(cards[4].getValue(), cards[0].getValue(), "TP");
        }
        return Sequence(cards[3].getValue(), cards[4].getValue(), "TP");
    }
    else if (equals == 1)
    {
        for (i = 1; i < 5; i++)
        {
            if (i < 4)
            {
                if (cards[i] == cards[i - 1])
                {
                    return Sequence(cards[i].getValue(), cards[4].getValue(), "OP");
                }
            }
        }
        return Sequence(cards[4].getValue(), cards[2].getValue(), "OP");
    }
    else
    {
        return Sequence(cards[4].getValue(), cards[4].getValue(), "HC");
    }
}