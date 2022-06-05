#include "card.h"
#include "player.h"
#include "hand.h"
#include "sequence.h"
#include <string>
#include <vector>
#include <cstring>
int main(int argc, char **argv)
{
    int i = 0, j = 0, u = 0;
    int nRodadas;
    int initialMoney;
    int players;
    int pingo;
    bool ping = false;
    int bet;
    int number;
    std::string name = "";
    std::string entry;
    std::string numbers;
    std::string naipe;
    std::cin >> nRodadas;
    std::cin >> initialMoney;
    Sequence * sequence;
    Card *cards[4];
    for (i = 0; i < nRodadas; i++)
    {
        std::cin >> players;
        std::cin >> pingo;
        for (j = 0; j < players; j++)
        {
            std::cin >> entry;
            while (!std::isdigit(entry[0]))
            {
                name += " "+entry;
                std::cin >> entry;
            }
            pingo = std::stoi(entry);
            for (u = 0; u < 5; u++)
            {
                std::cin >> entry;
                if (entry.length() == 3)
                {
                    number = std::stoi(entry.substr(0, 2));
                    naipe = entry.substr(2, 3);
                }
                else
                {
                    number = std::stoi(entry.substr(0, 1));
                    naipe = entry.substr(1, 2);
                }
                cards[u] = new Card(number, naipe);
            }
            Hand hand = Hand(cards);
            sequence = new Sequence(Sequence::getSequence(hand));
            std::cout<<sequence->sequence<<std::endl;
            name = "";
        }
    }
    return 0;
}