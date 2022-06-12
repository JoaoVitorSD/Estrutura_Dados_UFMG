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
    primeiro = new TurnCell();
    ultimo = primeiro;
}
ListaEncadeada::~ListaEncadeada()
{
    Limpa();
    delete primeiro;
}
void ListaEncadeada::InsereOrdenado(Player *player)
{
    TurnCell *aux = primeiro->next;
    TurnCell *next = aux;
    TurnCell *prev = aux;
    TurnCell *newP = new TurnCell();
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
    while (aux != nullptr)
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
TurnCell *ListaEncadeada::Posiciona(int pos, bool antes = false)
{
    TurnCell *p;
    int i;
    if ((pos > tamanho) || (pos <= 0))
        throw "ERRO: Posicao Invalida!";
    // Posiciona na célula anterior a desejada
    p = primeiro;
    for (i = 1; i < pos; i++)
    {
        p = p->next;
    }
    // vai para a próxima
    // se antes for false
    if (!antes)
        p = p->next;
    return p;
}

void ListaEncadeada::InsereFinal(Player *player)
{
    TurnCell *nova;
    nova = new TurnCell();
    nova->player->name = player->name;
    nova->player->money = player->money;
    ultimo->next = nova;
    ultimo = nova;
    tamanho++;
};

Player *ListaEncadeada::Pesquisa(Player *c)
{
    Player *aux;
    TurnCell *p;
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
    TurnCell *aux = primeiro->next;
    Player *p = aux->player;
    while (aux != nullptr)
    {
        p = aux->player;
        p->money= p->money - pingo;
        total +=pingo;
        aux = aux->next;
    }
    return total;
}
void ListaEncadeada::Imprime()
{
    std::cout << "####" << std::endl;
    TurnCell *aux = primeiro->next;
    Player *p = aux->player;
    while (aux != nullptr)
    {
        p = aux->player;
        std::cout << p->name << " " << p->money << std::endl;
        aux = aux->next;
    }
}
void ListaEncadeada::InsereInicio(Player *item)
{
    TurnCell *nova;
    nova = new TurnCell();
    nova->player = item;
    nova->next = primeiro->next;
    primeiro->next = nova;
    tamanho++;
    if (nova->next == NULL)
        ultimo = nova;
};

void ListaEncadeada::Limpa()
{
    TurnCell *p;
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