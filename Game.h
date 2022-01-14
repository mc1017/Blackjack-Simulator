#ifndef GAME_H
#define GAME_H
#include "Card.h"
#include "Deck.h"
#include <string>
#include <vector>
using namespace std;

class Games{
    public:
        void getDealer(std::vector<Card> &cards,Card c);
        void getPlayer(std::vector<Card> &cards,Card c);
        int getStrength(std::vector<Card> hand);
        int compareStrength(std::vector<Card> playerHand, std::vector<Card> dealerHand);
        string decisionChart(std::vector<Card> playerHand, std::vector<Card> dealerHand);
};
#endif