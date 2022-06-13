#include "list.h"
#include <algorithm>
int ListaEncadeada::compareString(std::string a, std::string b)
{
    int i = 0;
    int size1 = a.length();
    std::for_each(a.begin(), a.end(), [](char &c)
                  { c = ::toupper(c); });
    std::for_each(b.begin(), b.end(), [](char &c)
                  { c = ::toupper(c); });
    int size2 = b.length();
    for (i = 0; i < a.length(); i++)
    {
        if (i == a.length())
        {
            return 1;
            // a tem menos letras, então vem antes
        }
        if (i == b.length())
        {
            return 0;
            // b tem menos letras então vem antes
        }
        if (a[i] < b[i])
        {
            // a tem o numero ascii menor, então vem antes
            return 1;
        }
        if (a[i] > b[i])
        {
            // a tem um numero ascii maior então vem depois
            return 0;
        }
    }
    return -1;
    // as string são iguais;
}
ListaEncadeada::ListaEncadeada()
{
    primeiro = new PlayerCell();
    ultimo = primeiro;
}
ListaEncadeada::~ListaEncadeada()
{
    Limpa();
    delete primeiro;
}
void ListaEncadeada::InsereOrdenado(Player *player)
{
    PlayerCell *aux = primeiro->next;
    PlayerCell *next = aux;
    PlayerCell *prev = aux;
    PlayerCell *newP = new PlayerCell();
    newP->player = player;
    int u = 0;
    int pos;
    if (primeiro->next == nullptr)
    {
        primeiro->next = newP;
        ultimo = newP;
        tamanho++;
        return;
    }
    while (aux != nullptr)
    {
        if (compareString(newP->player->name, aux->player->name) == 1)
        {
            pos = u;
            break;
        }
        aux = aux->next;
        if (aux == nullptr)
        {
            ultimo->next = newP;
            ultimo = newP;
            tamanho++;
            return;
        }
        u++;
    }
    aux = primeiro;
    prev = aux;
    u = 0;
    while (u != pos + 2)
    {
        prev = aux;
        aux = aux->next;
        if (u == pos)
        {
            tamanho++;
            prev->next = newP;
            newP->next = aux;
        }
        u++;
    }
};
void ListaEncadeada::InsereFinal(Player *player)
{
    PlayerCell *nova;
    nova = new PlayerCell();
    nova->player->name = player->name;
    nova->player->money = player->money;
    ultimo->next = nova;
    ultimo = nova;
    tamanho++;
};

Player *ListaEncadeada::Pesquisa(Player *c)
{
    Player *aux;
    PlayerCell *p;
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    p = primeiro->next;
    while (p != NULL)
    {
        if (p->player->name == c->name)
        {
            aux = p->player;
            break;
        }
        p = p->next;
    }
    return aux;
};
int ListaEncadeada::discountPing(int pingo)
{
    int total = 0;
    PlayerCell *aux = primeiro->next;
    Player *p = aux->player;
     while (aux != nullptr)
    {
        p = aux->player;
        if (p->money < pingo)
        {
            invalid = true;
            return 0;
        }
        aux = aux->next;
    }
    aux=primeiro->next;
    while (aux != nullptr)
    {
        p = aux->player;
        if (p->money >= pingo)
        {
            p->money = p->money - pingo;
            total += pingo;
        }
        aux = aux->next;
    }
    return total;
}
void ListaEncadeada::Imprime()
{
    Player **players = new Player *[tamanho];
    PlayerCell *aux = primeiro->next;
    Player *p = aux->player;
    short size = 0;
    for (int i = 0; aux != nullptr; i++)
    {
        p = aux->player;
        players[i] = p;
        aux = aux->next;
        size++;
    }
    // agora será feita a ordenação por seleção dos jogadores pelo dinheiro
    short max;
    Player *auxP;
    for (int i = 0; i < size; i++)
    {
        max = i;
        for (int j = i + 1; j < size; j++)
        {
            if (players[j]->money > players[max]->money){
                    max = j;
            }
        }
        auxP->money = players[i]->money;
        auxP->name = players[i]->name;
        players[i]->money = players[max]->money;
        players[i]->name = players[max]->name;
        players[max]->money = auxP->money;
        players[max]->name = auxP->name;
    }
    std::cout << "####" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout<<players[i]->name <<" "<<players[i]->money<<std::endl;
    }
     for (int i = 0; i < size; i++)
    {
        delete players[i];
    }
    delete players;
}
void ListaEncadeada::printPlayers(){
    PlayerCell *aux = primeiro->next;
    Player *p = aux->player;
    for (int i = 0; aux != nullptr; i++)
    {
        p = aux->player;
        std::cout<<p->name<<std::endl;
        aux = aux->next;
    }
}
void ListaEncadeada::InsereInicio(Player *item)
{
    PlayerCell *nova;
    nova = new PlayerCell();
    nova->player = item;
    nova->next = primeiro->next;
    primeiro->next = nova;
    tamanho++;
    if (nova->next == NULL)
        ultimo = nova;
};

void ListaEncadeada::Limpa()
{
    PlayerCell *p;
    p = primeiro->next;
    while (p != NULL)
    {
        primeiro->next = p->next;
        delete p;
        p = primeiro->next;
    }
    ultimo = primeiro;
    tamanho = 0;
};