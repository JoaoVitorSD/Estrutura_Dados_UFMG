#include "card.h"
#include "player.h"
#include "hand.h"
#include "sequence.h"

int main(int argc, char ** argv){
    Card cards[4];
    cards[0] = Card(2,'C');
    cards[1] = Card(5,'O');
    cards[2] = Card(5,'P');
    cards[3] = Card(5,'E');
    cards[4] = Card(2,'O');
    Hand * hand = new Hand(cards);
    Player * player = new Player("João");
    Sequence::getSequence(hand->cards);
    return 0;
}               