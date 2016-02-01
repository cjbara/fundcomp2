//Cory Jbara - lab 4
//Interface for the BlackJack class
//This class contains a CardDeck in it

#ifndef BLACKJACK_H
#define BLACKJACK_H
#include "CardDeck.h"
#include <deque>

class BlackJack {

  public:
    BlackJack();
    void playBlackJack(); //begins the game of BlackJack
  
  private:
    CardDeck deck;
    int playerWins;
    int dealerWins;
  //playerhand and dealerhand are vectors of ints that hold the users and dealers hands
    deque<int> playerHand;
    deque<int> dealerHand;
  //playerInput is h or s and determines whether player wil hit or stand
    char playerInput;
    int sum(deque<int>);//computes the sum of a hand, input is player hand or dealer hand

};

#endif
