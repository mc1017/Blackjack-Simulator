#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;
class Card{
    public:
        Card(int suit, int num);
        std::string to_s();
        int s;
        int v;
    private:
        std::vector<Card> deck;      
};
#endif
