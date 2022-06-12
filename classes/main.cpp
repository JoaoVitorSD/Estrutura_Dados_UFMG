#include "card.h"
#include "player.h"
#include "hand.h"
#include "sequence.h"
#include "turn.h"
#include "list.h"
#include <string>
#include <list>
#include <cstring>

int main(int argc, char **argv)
{
    int i = 0, j = 0, u = 0;
    int nRodadas;
    int initialMoney;
    int players;
    int bet;
    int bowl=0;
    bool ping = false;
    int pote = 0;
    short winners = 0;
    int number;
    std::string name = "";
    std::string entry;
    std::string numbers;
    std::string naipe;
    std::cin >> nRodadas;
    std::cin >> initialMoney;
    Card *cards[5];
    Turn **turns;
    ListaEncadeada *list = new ListaEncadeada();
    std::string string1 = "ANA";
    std::string string2 = "BRUNO";
    // std::cout<<list->compareString(string1,string2);
    Player * player;
    for (i = 0; i < nRodadas; i++)
    {
        bowl=0;
        winners = 0;
        std::cin >> players;
        std::cin >> bet;
        Sequence *maior = new Sequence(-1, -1, "", -1);
        turns = new Turn *[players];
        for (j = 0; j < players; j++)
        {
            std::cin >> entry;
            name = entry;
            std::cin >> entry;
            bet = std::stoi(entry);
            bowl+=bet;
            if (i == 0)
            {
                player = new Player(name, initialMoney);
                list->InsereOrdenado(player);
            }
            else
            {
                player = new Player(name, initialMoney);
            }
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

            if (Sequence::isLess(maior, sequence) == 1)
            {
                maior = sequence;
            };
            turns[j] = new Turn(sequence, player, bet);
            name = "";
        }
        for (u = 0; u < players; u++)
        {
            if (Sequence::isLess(turns[u]->sequence, maior) == -1)
            {
                winners++;
            }
        }
        std::cout<<winners<<" "<<bowl<<" "<<maior->sequence<<std::endl;
        for(u=0;u<players;u++){
                Player * player = list->Pesquisa(turns[u]->player);
            if (Sequence::isLess(turns[u]->sequence, maior) == -1)
            {
                std::cout<<turns[u]->player->name<<std::endl;
                if(winners==1){
                player->money+=bowl-turns[u]->bet;
                }
                else{
                    player->money=bowl*(bowl/turns[u]->bet);
                }
            }else{
                player->money-=turns[u]->bet;
            }
        }
        list->Imprime();
        delete turns;
        delete maior;
    }
    return 0;
}