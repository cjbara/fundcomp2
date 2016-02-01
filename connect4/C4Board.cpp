/* Cory Jbara - Fund Comp 2 - Lab 1
 * Implementation for class C4Board */

#include <iostream>
#include <cstdlib>
#include "C4Board.h"
#include "C4Col.h"
using namespace std;

//default constructor uses 7 total columns
C4Board::C4Board(){
  numCols=7;
  Board=new C4Col[numCols];
}

//display displays the board on the screen
void C4Board::display(){
  //cout << "\033[2J\033[1;1H";	//clears screen
  
  for(int i=1;i<=numCols;i++){//Shows column number column 
	if(i<10) cout << "  " << i << " ";
	else cout << " " << i << " ";
  }
  cout << endl;
  
  int j=Board[0].getMaxDiscs()-1;
  for(j; j>=0; j--){	//prints last element of the column first
    cout << "| ";
    for(int i=0; i<numCols; i++){				//from row 0-numCols
	cout << Board[i].getDisc(j) << " | ";		//print each column
    } cout << endl;					//new line after column
  } cout << endl;
}

//plays the game
void C4Board::play(int players){
  int turn=0;		//will calculate whose turn it is (0=p1, 1=p2)
  int rowInput;
  do{ 
    if(players==1 && turn==1) { rowInput=compMove(); }//if one player and p2 is up, use compMove
    else {cout << "Player " << turn+1 << ((turn==0)? " (X)" : " (O)") << ", which column would you like to put your disc?" << endl;
      cin >> rowInput;
    }	//This else will run for human players
    while(rowInput>numCols || rowInput<=0){	//This loop makes sure the column input is a valid column
	cout << "That is not a column on the board. Please enter a valid column number." << endl;
	cin >> rowInput;
    }
    rowInput--;			//changes user input to index
    char add;			//char of disc to add (X for P1 O for P2)
    if(turn==0){
	add='X';	
    } else { 
	add='O';
    }
    if(Board[rowInput].addDisc(add)){	//Places letter, if not placed successfully
	continue;			//continue and obtain another input from user
    }
    display();				//Displays board
    if(isGameOver()) return;
    turn++;
    turn=turn%2;			//will always be 0 or 1
  } while(1);
}

//returns 1 if game is over, or 0 if otherwise
int C4Board::isGameOver(){
  for(int i=0;i<numCols;i++){			//loops through columns
    for(int j=0;j<Board[i].getMaxDiscs();j++){	//loops through rows 
    //(remember the display is backwards, (0,0) is bottom left)
	//cout << "(" << i << "," << j << ")" << endl;
	if(j<Board[i].getMaxDiscs()-3){	//checks for vertical wins (only runs on valid index)
	  if(Board[i].getDisc(j)==Board[i].getDisc(j+1) && Board[i].getDisc(j)==Board[i].getDisc(j+2) && Board[i].getDisc(j)==Board[i].getDisc(j+3) && Board[i].getDisc(j)!=' ')
	  { cout << "Player " << ((Board[i].getDisc(j)=='X')? "1 " : "2 ") << "wins!" << endl;
	    return 1; }
	}
	if(i<numCols-3){		//checks for horizontal winner
	  if(Board[i].getDisc(j)==Board[i+1].getDisc(j) && Board[i].getDisc(j)==Board[i+2].getDisc(j) && Board[i].getDisc(j)==Board[i+3].getDisc(j) && Board[i].getDisc(j)!=' ')
	  { cout << "Player " << ((Board[i].getDisc(j)=='X')? "1 " : "2 ") << "wins!" << endl;
            return 1; }
        }
	if(i<numCols-3 && j<Board[i].getMaxDiscs()-3){	//Checks for right diagonal
	  if(Board[i].getDisc(j)==Board[i+1].getDisc(j+1) && Board[i].getDisc(j)==Board[i+2].getDisc(j+2) && Board[i].getDisc(j)==Board[i+3].getDisc(j+3) && Board[i].getDisc(j)!=' ')
	  { cout << "Player " << ((Board[i].getDisc(j)=='X')? "1 " : "2 ") << "wins!" << endl;
            return 1; }
        }
	if(i>2 && j<Board[i].getMaxDiscs()-3){  //Checks for left diagonal
          if(Board[i].getDisc(j)==Board[i-1].getDisc(j+1) && Board[i].getDisc(j)==Board[i-2].getDisc(j+2) && Board[i].getDisc(j)==Board[i-3].getDisc(j+3) && Board[i].getDisc(j)!=' ')
          { cout << "Player " << ((Board[i].getDisc(j)=='X')? "1 " : "2 ") << "wins!" << endl;
	  return 1; }
        }
    }
  }
  //Check if the board is full
  for(int i=0;i<numCols;i++){                   //loops through columns
	if(!Board[i].isFull())	return 0; 	//if there is a non-blank, the game continues
  }
  cout << "The board is full! It's a tie!" << endl;
  return 1;
}

//Computer places piece randomly
int C4Board::compMove(){
  int comp=0;
  do{
    comp = rand()%numCols+1;
  } while(Board[comp].isFull());     //This loop makes sure the column input is a valid column
  return comp;
}
