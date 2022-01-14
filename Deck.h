#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <string>
#include <vector>
using namespace std;

class Deck{
    public:

        Deck(int numDecks);
        std::vector<Card> getDeck(int numDecks);
        void shuffledeck(std::vector<Card> &Deck, int numDecks);

    private:
        std::string s;
        int numDecks;
        std::vector<Card> deck;
};
#endif