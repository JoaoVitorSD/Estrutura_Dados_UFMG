#include "cell.h"

class ListaEncadeada
{
public:
    ListaEncadeada();
    ~ListaEncadeada();
    void InsereInicio(Player *item);
    void InsereFinal(Player *item);
    void InsereOrdenado(Player *item);
    void printPlayers();
    static int compareString(std::string a, std::string b);
    int discountPing(int pingo);
    Player * Pesquisa(Player *c);
    void Imprime();
    void Limpa();
    int tamanho;
    PlayerCell *primeiro;
    PlayerCell *ultimo;
    bool invalid=0;
};