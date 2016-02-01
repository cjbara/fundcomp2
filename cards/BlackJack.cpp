//Cory Jbara - lab 4
//Implementation for BlackJack class
//Only includes constructor and playBlackJack function, along with many private members

#include "BlackJack.h"
#include <iostream>
#include <deque>
using namespace std;

BlackJack::BlackJack(){
  playerWins=0;
  dealerWins=0;
  playerInput='h';
  deck.newDeck(); 
}

void BlackJack::playBlackJack(){
  //playAgain is updated after each round of blackjack, either stays 'y' or is made 'n' if 
  //the user doesn't want to play again
  char playAgain='y';

  //is changed to 1 when the player busts
  int playerBust=0;
  int dealerBust=0;
  
  //each loop of thw while loop is one game of BlackJack
  while(playAgain!='n'){
    playerBust=0;
    dealerBust=0;
    playerHand.clear();
    dealerHand.clear();
    
    //deal 2 cards to each player
    playerHand.push_back(deck.Deal());
    playerHand.push_back(deck.Deal());
    dealerHand.push_back(deck.Deal());

    //this loop is for the player to hit or stand, once they stand or get over 21
    do {
      //tell them what they have and ask if they want to hit or stand
      cout << "You have " << sum(playerHand) << endl;
      //check for blackjack
      if(sum(playerHand)==21 && playerHand.size()==2){
	cout << "You got BlackJack! You win!" << endl;
	playerWins++;
	break;
      }
      //now ask to hit or stand
      cout << "The dealer's up card is " << sum(dealerHand) << endl << "Hit or stand? (h/s) ";
      cin >> playerInput;
      if(playerInput=='h'){//give them another card
	playerHand.push_back(deck.Deal());
	//print their new sum
	cout << "Player Hits" << endl;
      }
      if(sum(playerHand)>21){
	//busted hand
	cout << "You have " << sum(playerHand) << endl;
	cout << "Sorry, you busted!" << endl;
	playerInput='s';
	playerBust = 1;
      }
    } while(playerInput!='s');
  
    //if the player busted in the previous loop, dealer wins, else keep playing
    if(playerBust==1){
	dealerWins++;
	cout << "The dealer won this hand. " << endl;
    } else {
	//now that the player stood, flip (deal) dealer's second card 
        dealerHand.push_back(deck.Deal());
	cout << "The dealer flips his other card and has " << sum(dealerHand) << "." << endl;
	while(sum(dealerHand)<17){
	  //dealer must hit
	  cout << "The dealer hits." << endl;
	  dealerHand.push_back(deck.Deal());
	  cout << "The dealer has " << sum(dealerHand) << "." << endl;
	}
	
	//now the dealer has >17, check if he busted
	if(sum(dealerHand)>21){//dealer busts, player wins
	  dealerBust=1;
	  cout << "The dealer busted. " << endl;
	  playerWins++;
	} else {//dealer didn't bust, whoever has the highest value wins
	  cout << "You have " << sum(playerHand) << " and the dealer has " << sum(dealerHand)<<endl;
	  if(sum(playerHand) > sum(dealerHand)){//player wins
		cout << "You win!" << endl;
		playerWins++;
	  } else {
		cout << "Sorry, you lost." << endl;
		dealerWins++;
	  }
	}

    }
    //display stats
    cout << endl << "Player Wins: " << playerWins;
    cout << endl << "Dealer Wins: " << dealerWins << endl;
    //ask to play again
    cout << "Do you want to play again? (y/n) ";
    cin >> playAgain;
    cout << endl;
  }
}

//computes sum of a hand
int BlackJack::sum(deque<int> hand){
  int handSum=0;  //is the sum of th hand to be returned
  deque<int>::const_iterator i=hand.begin();
  int temp;

  //now lop through the hand, but with some special rules:
  //0 - kings, count as 10
  //1 - Aces, count as 11
  //11 - jacks, count as 10
  //12 - queens, count as 10
  for(i; i!=hand.end(); ++i){
    //first make each card readable by using %13
    temp = *i;
    temp = temp %13;
    if(temp==0 || temp==11 || temp==12){//king, queen or jack, add 10
    	handSum += 10;
    } else if(temp==1){//ace, add 11
	handSum += 11;
    } else {//otherwise add the card number
	handSum += temp;
    }
  }
  
  return handSum;
}
