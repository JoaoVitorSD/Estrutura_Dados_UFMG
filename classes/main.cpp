#include "card.h"
#include "player.h"
#include "hand.h"
#include "sequence.h"
#include "turn.h"
#include <string>
#include <list>
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
    Card *cards[5];
    std::list<Turn> turns;
    short **results = new short *[nRodadas];
    for (i = 0; i < nRodadas; i++)
    {
        std::cin >> players;
        results[i] = new short[players];
        std::cin >> pingo;
        short maior = -1;
        for (j = 0; j < players; j++)
        {
            std::cin >> entry;
            name = entry;
            std::cin >> entry;
            pingo = std::stoi(entry);
            for (u = 0; u < 5; u++)
            {
                std::cin >> entry;
                if (entry.length() == 3)
                {
                    number = std::stoi(entry.substr(0, 2));
                    naipe = entry.at(2);
                }
                else
                {
                    number = std::stoi(entry.substr(0, 1));
                    naipe = entry.at(1);
                }
                cards[u] = new Card(number, naipe);
            }
            Hand *hand = new Hand(cards);
            Sequence *sequence = Sequence::getSequence(hand);
            if (maior < sequence->sequence_value)
            {
                maior = sequence->sequence_value;
            };
            std::cout << sequence->sequence_value<< std::endl;
            Player *player = new Player(name, initialMoney);
            Turn turn = Turn(sequence, player, pingo);
            turns.push_back(turn);
            name = "";
            results[i][j] = sequence->sequence_value;
        }
        std::list<Turn>::iterator it = turns.begin();
        for (it; it != turns.end(); it++)
        {
            if (it->sequence->sequence_value == maior)
            {
                std::cout << it->sequence->sequence_value << "vencedor" << std::endl;
            }
        }
        turns.clear();
    }
    return 0;
}