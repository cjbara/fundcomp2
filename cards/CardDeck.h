//Cory Jbara - lab4 - CardDeck interface
//CardDeck class stores a deque called deck, which is a deck of cards

#ifndef CARDDECK_H
#define CARDDECK_H
#include <deque>
#include <iostream>
using namespace std;

class CardDeck {
  friend ostream& operator<<(ostream&, CardDeck&);

  public:
    CardDeck(int=52);
    int getSize();
    void shuffle();
    int inOrder();
    int monkeySort();
    int Deal();
    void newDeck();

  private:
    deque<int> deck;
    int deckSize;

};

#endif
