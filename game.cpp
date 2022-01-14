#include "Card.h"
#include "Deck.h"
#include "Game.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void Games::getDealer(std::vector<Card> &cards, Card c){
    cards.push_back(c);

}
void Games::getPlayer(std::vector<Card> &cards, Card c){
    cards.push_back(c);
}

int Games::getStrength(std::vector<Card> hand){
    int strength=0;
    bool ace=false;
    for (int i=0; i<hand.size();i++){
        switch (hand[i].v){
            case 1:
                if (ace==true){
                    strength+=1;
                }
                else{
                    
                    if ((strength+11)>21){
                        strength+=1;
                    }
                    else{
                        strength+=11;
                        ace=true;
                    }
                }
                break;
            case 11:
                strength+=10;   
                break;
            case 12:
                strength+=10;
                break;
            case 13:
                strength+=10;
                break;
            default:
                strength+=hand[i].v;
                break;
            }
    }
    if (ace==true){
        if (strength>21){
            strength=strength-10;
        }
    }
    return strength;
}

//return true when player won
int Games::compareStrength(std::vector<Card> playerHand, std::vector<Card> dealerHand){
    if(Games::getStrength(playerHand)>Games::getStrength(dealerHand)){
        return 1;
    }
    else if (Games::getStrength(playerHand)==Games::getStrength(dealerHand)){
        return 0;
    }
    else{
        return -1;
    }


}

string Games::decisionChart(std::vector<Card> playerHand, std::vector<Card> dealerHand){
    int player=Games::getStrength(playerHand);
    int dealer=Games::getStrength(dealerHand);
    if(player<=8){
        return "H";
    }
    else if (player>=17){
        return "S";
    }
    else if (player>=13 && dealer<=6){
        return "S";
    }
    else if (player>=13 && dealer>=7){
        return "H";
    }
    else if (player ==12 && (dealer>=7 || dealer<=3)){
        return "H";
    }
    else if (player==12){
        return "S";
    }
    else if (player==11){
        return "D";
    }
    else if (player==10 && dealer<=9){
        return "D";
    }
    else if (player==10){
        return "H";
    }
    else if (player==9 && (dealer>=7 || dealer==2)){
        return "H";
    }
    else{
        return "D";
    }
    
}