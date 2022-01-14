#include "Card.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

Card::Card(int suit, int num){
    s=suit;
    v=num;
}
string Card::to_s(){
    string suit;
    string value;
    switch(v){
        case 1:
            value="Ace of ";
            break;
        case 2:
            value="Two of ";
            break;
        case 3:
            value="Three of ";
            break;
        case 4:
            value="Four of ";
            break;
        case 5:
            value="Five of ";
            break;
        case 6:
            value="Six of ";
            break;
        case 7:
            value="Seven of ";
            break;
        case 8:
            value="Eight of ";
            break;
        case 9:
            value="Nine of ";
            break;
        case 10:
            value="Ten of ";
            break;
        case 11:
            value="Jack of ";
            break;
        case 12:
            value="Queen of ";
            break;
        case 13:
            value="King of ";
            break;
    }
    switch(s){
        case 1:
            suit="Spades";
            break;
        case 2:
            suit="Hearts";
            break;
        case 3:
            suit="Clubs";
            break;
        case 4:
            suit="Diamonds";
            break;
    }
    return value+suit;
}

