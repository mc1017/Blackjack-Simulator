#include "Card.h"
#include "Deck.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;


Deck::Deck(int numDecks){
    numDecks=numDecks;

}
std::vector<Card> Deck::getDeck(int numDecks){
    std::vector<Card> deck;
    
    for (int i=0; i<numDecks; i++){
        for (int s=1; s<=4; s++){
            for (int v=1; v<=13;v++){
                Card c(s,v);
                deck.push_back(c);
            } 
        }
    }
    
    return deck;
}
void Deck::shuffledeck(std::vector<Card> &card,int numDecks){
    
    // Initialize seed randomly
    srand(time(0));
  
    for (int i=0; i<numDecks*52 ;i++)
    {
        // Random for remaining positions.
        int r = i + (rand() % (52*numDecks -i));
  
        swap(card[i], card[r]);
    }

}

