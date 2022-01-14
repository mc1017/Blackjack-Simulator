#include "Card.h"
#include "Deck.h"
#include "Game.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

void startGame(std::vector<Card> &cards,std::vector<Card> &playerHand,std::vector<Card> &dealerHand, Games game){
    game.getPlayer(playerHand, cards.back());
    cards.pop_back();
    game.getDealer(dealerHand, cards.back());
    cards.pop_back();
    game.getPlayer(playerHand, cards.back());
    cards.pop_back();
    cout<<"Your Cards Strength: "<<game.getStrength(playerHand)<<endl;
    for (int i=0; i<playerHand.size();i++){
        cout<<playerHand[i].to_s()<<endl;
    }
    cout<<"Dealer Cards Strength: "<<game.getStrength(dealerHand)<<endl;
    for (int i=0; i<dealerHand.size();i++){
        cout<<dealerHand[i].to_s()<<endl;
    }
}

int main(){
    int numDecks;
    int numGames;
    int numRounds;
    // cout<<"How many decks of cards?"<<endl;
    // cin>>numDecks;
    numDecks=4;

    Deck initdeck(numDecks);
    std::vector<Card> cards;
    cards = initdeck.getDeck(numDecks);

    cout<<"How many rounds are you playing?"<<endl;
    cin>>numRounds;
    cout<<"How many games are you playing?"<<endl;
    cin>>numGames;

    int numLost=0;
    int amountGain=0;
    int amountLost=0;
    int totalInvestment=10000;
    int bankroll=0;
    int gamestoMax=0;
    int avgggamestoMax=0;
    double win=0;
    double lose=0;
    double push=0;
    for (int j=0; j<numRounds; j++){
        
        // cout<<"How much do you buy-in?"<<endl;
        // cin>> bankroll;
        bankroll=10000;
        
        initdeck.shuffledeck(cards,numDecks);
        // for (int i=0; i<cards.size(); i++){
        //     cout<<cards[i].to_s()<<endl;
        // }
        int cardtracker=0;
        std::vector<Games> game;
        bool lostLast=false;
        int bet=10;
        

        
        
        for (int i=0; i<numGames; i++){

            cout<<"Game: "<<i+1<<endl;
            //playerWon -1 = lose, playerWon 0 = push, playerWon 1 = Win
            

            int playerWon=-1;
            bool playerBusted=false;
            string draw;

            std::vector<Card> playerHand;
            std::vector<Card> dealerHand;
            // if (bankroll<=0){
            //     cout<<"Bankrupt"<<endl;
            //     numLost++;
            //     amountLost+=totalInvestment-bankroll;
            //     break;
            // }
            
            
            // // cout<<"How much do you bet?"<<endl;
            // // cin>>bet;
            // //manual bet
            // if(lostLast){
            //     bet=bet*2;
            //     if (bet>5000){
            //         cout<<"Took "<<i<<" Games to reach maximum bet of 5000"<<endl;
            //         if (bankroll<totalInvestment){
            //             numLost++;
            //             amountLost+=totalInvestment-bankroll;
            //         }
            //         else{
            //             amountGain+=bankroll-totalInvestment;
            //         }
            //         gamestoMax+=i;
            //         avgggamestoMax++;
            //         break;
            //     }
            //     if (bankroll<bet){
            //         cout<<"No more bets"<<endl;
            //         if (bankroll<totalInvestment){
            //             numLost++;
            //             amountLost+=totalInvestment-bankroll;
            //         }
            //         else{
            //             amountGain+=bankroll-totalInvestment;
            //         }
            //         gamestoMax+=i;
            //         avgggamestoMax++;
            //         break;
            //     }
            // }
            // else{
            //     bet=10;
            // }
            startGame(cards,playerHand, dealerHand, game[i]);
            if (game[i].getStrength(playerHand)==21 && game[i].getStrength(dealerHand)!=10 && game[i].getStrength(dealerHand)!=11){
                playerWon=2;
            }
            else{
                // cout<<"Hit, Stand or Double? (H/S/D)?"<<endl;
                
                //cin>>draw;
                //manual input

                //automated input
                draw=game[i].decisionChart(playerHand,dealerHand);
                if (draw=="H"){
                    cout<<"Hit"<<endl;
                }
                else if(draw=="S"){
                    cout<<"Draw"<<endl;
                }
                if (draw=="D"){
                    bet=bet*2;
                    cout<<"Double"<<endl;
                }
                //Player Draw
                while (draw=="H" || draw=="D"){
                    game[i].getPlayer(playerHand, cards.back());
                    cards.pop_back();
                    if (game[i].getStrength(playerHand)>21){
                        cout<<"You busted: "<<game[i].getStrength(playerHand)<<endl;
                        for (int i=0; i<playerHand.size();i++){
                            cout<<playerHand[i].to_s()<<endl;
                        }
                        playerBusted=true;
                        playerWon= -1;
                        break;
                    }
                    else{
                        cout<<"Your Cards Strength: "<<game[i].getStrength(playerHand)<<endl;
                        for (int i=0; i<playerHand.size();i++){
                            cout<<playerHand[i].to_s()<<endl;
                        }
                        cout<<"Dealer Cards Strength: "<<game[i].getStrength(dealerHand)<<endl;
                        for (int i=0; i<dealerHand.size();i++){
                            cout<<dealerHand[i].to_s()<<endl;
                        }
                        if (draw=="D"){
                            draw="S";
                        }
                        else{
                            // cout<<"Hit or Stand (H/S)?"<<endl;
                            // cin>>draw;
                            //manual input;

                            draw=game[i].decisionChart(playerHand,dealerHand);
                            if (draw=="H"){
                                cout<<"Hit"<<endl;
                            }
                            else if(draw=="S"){
                                cout<<"Draw"<<endl;
                            }
                        }
                    }
                    
                }
                if(playerBusted==false){
                    game[i].getDealer(dealerHand, cards.back());
                    cards.pop_back();
                    if (game[i].getStrength(dealerHand)==21){
                        cout<<"Dealer Blackjack"<<endl;
                        playerWon=-1;
                    }
                    else{
                        while(game[i].getStrength(dealerHand)<17){
                            game[i].getDealer(dealerHand, cards.back());
                            cards.pop_back();
                        }
                        
                        if (game[i].getStrength(dealerHand)>21){
                            cout<<"Dealer Busted: "<<game[i].getStrength(dealerHand)<<endl;
                            for (int i=0; i<dealerHand.size();i++){
                                cout<<dealerHand[i].to_s()<<endl;
                            }
                            playerWon=1;
                        }
                        else{
                            cout<<"Dealer Cards Strength: "<<game[i].getStrength(dealerHand)<<endl;
                            for (int i=0; i<dealerHand.size();i++){
                                cout<<dealerHand[i].to_s()<<endl;
                            }
                            playerWon= game[i].compareStrength(playerHand,dealerHand);
                        }
                    }
                    
                }
            }
            if (playerWon==2){
                bankroll+=bet*3/2;
                cout<<"Blackjack! You Won: " <<bet*3/2<<endl;
                lostLast=false;
                win++;
            }
            else if (playerWon==1){
                bankroll+=bet;
                cout<<"You Won: " <<bet<<endl;
                lostLast=false;
                win++;
            }
            else if (playerWon ==0){
                cout<<"Push"<<endl;
                if (lostLast==true){
                    bet=bet/2;
                }
                push++;
            }
            else{
                bankroll-=bet;
                cout<<"You Lost: "<<bet<<endl;
                lostLast=true;
                lose++;
            }
            cout<<"Bankroll: "<<bankroll<<endl;

            // if (i==(numGames-1)){
            //     if (bankroll<totalInvestment){
            //         numLost++;
            //         amountLost+=totalInvestment-bankroll;
            //     }
            //     else{
            //         amountGain+=bankroll-totalInvestment;
            //     }
            // }

            if (cards.size()<10){
                cards = initdeck.getDeck(numDecks);
                initdeck.shuffledeck(cards,numDecks);
            }
            if (draw=="D"){
                bet=bet/2;
            }
            cout<<endl;          
        }
        

    } 
    // cout<<"Games lost: "<<numLost<<endl;
    // if (avgggamestoMax!=0){
    //     cout<<"Average game to reach 5000: "<<gamestoMax/avgggamestoMax<<endl;
    // }
    // cout<<"Total lost: "<<amountLost<<endl;
    // cout<<"Total gain: "<<amountGain<<endl;
    cout<<"Win percentage: "<<win/numGames*100<<"%"<<endl;
    cout<<"Push percentage: "<<push/numGames*100<<"%"<<endl;
    cout<<"Lose percentage: "<<lose/numGames*100<<"%"<<endl;

}