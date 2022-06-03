#include <iostream>
#ifndef Card_H
#define Card_H

class Card{
    private:
    short value;
    char naipe;

    public:
    Card();
    Card(short value, char naipe);
    short getValue(){return value;};
    char getNaipe(){return  naipe;};
    void setValue(short value);
    void setNaipe(char naipe);
    std::string getCard(){return std::to_string(value)+naipe+" ";}
  
    bool operator<(Card  card){
        return getValue()<card.getValue();
    }
    bool operator>(Card  card){
        return getValue()>card.getValue();
    }
    bool operator==(Card  card){
        return getValue()==card.getValue();
    }
    bool operator!=(Card  card){
        return getValue()!=card.getValue();
    }

};
#endif