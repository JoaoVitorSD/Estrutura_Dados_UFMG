#include <iostream>
#ifndef Card_H
#define Card_H

class Card{
    private:
    short value;
    std::string naipe;

    public:
    Card();
    Card(short value, std::string naipe);
    short getValue(){return value;};
    std::string getNaipe(){return  naipe;};
    void setValue(short value);
    void setNaipe(std::string naipe);
    std::string getCard(){return std::to_string(value)+naipe;}
  
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