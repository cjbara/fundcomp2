/* Cory Jbara - Fund Comp 2 - Lab 1
 * Interface for class C4Board */

#include "C4Col.h"
#ifndef C4BOARD_H
#define C4BOARD_H

class C4Board{
  
  public:
    C4Board();
    void display();
    void play(int);	//Input is number of players

  private:
    int numCols;	//Number of columns to have on the board
    C4Col *Board;
    int isGameOver();	//returns 1 if game is over, 0 otherwise
    int compMove();	//outputs random column
};

#endif
