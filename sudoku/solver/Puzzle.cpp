
//Puzzle implementation
//takes and reads input board within the constructor

#include "Puzzle.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <typename T>
Puzzle<T>::Puzzle(string fileName){
  //declare new filestream and open filename
  fstream inFile;
  inFile.open (fileName.c_str());

  T input;
  vector<T> tempVec;

  //read inputs into the board
  while(!inFile.eof()){
    for(int i=0; i<9; i++){
        inFile >> input;
        tempVec.push_back(input);
    }
    if(!inFile.eof()){
      board.push_back(tempVec);
      tempVec.clear();
    }
  }
  //make initial equal to board
  //initial is good to make sure users only delete the numbers they entered
  initial=board;

  //initialize possible vector
  //for numbers that are already locked in, enter these into the possible array
  //temp1 is pushed to the back of temp2, which is then pushed to the back of possible  
  vector<int> temp1;
  vector< vector <int> > temp2;

  for(int i=0; i<9; i++){
    for(int j=0; j<9; j++){
      if(board[i][j]!=0) temp1.push_back(board[i][j]);
      temp2.push_back(temp1);
      //reset temp1
      temp1.clear();
    }
    possible.push_back(temp2);
    //reset temp2
    temp2.clear();
  }
}

//prints the puzzle to the board
template <typename T>
void Puzzle<T>::print(){
  cout << endl;
  
  //insert column formatting
  cout << "\t        COLUMN:" << endl;
  cout << "\t 1 2 3   4 5 6   7 8 9" << endl;
  cout << "       +-------+-------+-------+" << endl;
  
  //two loops, for each row and column
  for(int i=0; i<board.size(); i++){
    if(i==4) cout << "ROW: ";
    else cout << "     ";
    cout << i+1 << " | ";
    for(int j=0; j<board[i].size(); j++){
        //print each number
        if(board[i][j]==0 || board[i][j]=='0'){ cout << "  "; }
        else { cout << board[i][j] << " "; }
	if(j%3==2)	cout << "| ";
    } 
    cout << endl;
    if(i%3==2)	cout << "       +-------+-------+-------+" << endl;
  }
  cout << endl;
}

template <typename T>
void Puzzle<T>::play(){
  //user enters their choice into the variable input, and then the corresponding function is called
  char input;
  int row, col;
  T element;

  print();

  while(!isFull()){
    cout<< "What would you like to do?" << endl
	<< "i: insert a new element onto the board" << endl
	<< "d: delete an element from the board" << endl
	<< "r: reset to board to the original board" << endl
	<< "q: quit the game" << endl;
    cin >> input;
    
    if(input=='q')  return;
    else if(input=='r')  reset();
    else if(input!='i' && input!='d'){
	cout << "That is not a valid command" << endl;
    } else {//either insert or remove
	cout << "Which row? ";
	cin >> row;
	cout << "Which column? ";
	cin >> col;
        //decrement the variables for proper indexing
  	row--;
  	col--;
	if(input=='d')	remove(row,col);
	else {//insert a new element
	  cout << "What " << ((sizeof(T)==4)?"number":"letter") <<" do you want to insert at ("
		<< row << "," << col << ")? ";
	  cin >> element;
	  insert(row,col,element);
	}
    }
    cout << endl;
  }
} 

//this is the solving function
template <typename T>
void Puzzle<T>::solve(){
  //now that possible is initialized, check which spaces in the array are available
  while(!isFull()){
  //We want to loop through this until no numbers are updated, and then we go to the singleton methods
  int prev = unfilled();
  do {
    prev = unfilled();
    for(int i=0; i<9; i++){
      for(int j=0; j<9; j++){
        //clear this vector from the last iteration
        if(possible[i][j].size()!=1) possible[i][j].clear();
        for(int k=0; k<9; k++){
	  //push any potential values to the 3rd dimension of the array
	  if(!check(i,j,k+1)){
	    possible[i][j].push_back(k+1);
	  } 
        }
        //if the size of the 3rd dimension of a vector is 1, then it is the only possibility
        //now insert it into the board, and loop through until nothing else gets updated
        if(possible[i][j].size()==1){
	  //board must be the only possible value (index 0) in possible[i][j]
	  board[i][j]=possible[i][j][0];
        }
      }
    }
  } while(unfilled()!=prev && !isFull());

    /*
    //This block displays the potential values for each square in the grid
    for(int i=0; i<9;i++){
      for(int j=0; j<9; j++){
        cout << endl << "Row: " << i+1 << ", Col: " << j+1 << "--------------";
        for(int z=0;z<possible[i][j].size();z++) {cout<<possible[i][j][z]<<", ";}
      }	
    } 
    */

    int beforeSingleton; //if any singleton method updates the board, you must repopulate the possible vector
    //check singleton method for each minibox
    beforeSingleton=unfilled();
    singletonBox();
    //if singletonBox changed anything, continue
    if(unfilled() != beforeSingleton) continue;
    
    //check singleton method for the row
    beforeSingleton=unfilled();
    singletonRow();
    //if singletonRows changed anything, continue
    if(unfilled() != beforeSingleton) continue;

    //check the singleton method for each column
    beforeSingleton=unfilled();
    singletonCol();
    //if singletonCols changed anything, continue
    if(unfilled() != beforeSingleton) continue;
  }
  //after it is solved, print the board
  print();
}

//this function implements the singleton method on a row
template <typename T>
void Puzzle<T>::singletonRow(){
  //declare and initialize
  //possRows is a 2d vector: 1st dimension is the number 0-9,
  //2nd dimension stores the columns in which the number appears
  vector<int> temp;
  vector< vector<int> > possCols;
  //initialize possCols
  for(int i=0; i<=9; i++) possCols.push_back(temp);
  vector<int>::iterator k;

  //do singleton for all rows
  for(int row=0; row<9; row++){
   for(int col=0; col<9; col++){//this loops through the columns of a single row
    for(k=possible[row][col].begin(); k != possible[row][col].end(); ++k){//loops through all possible values for cell (row,col)
      if(board[row][col]==0){//if the number isn't already filled in on the board
	//stores all of the columns in which a number can go
	//cout << row+1 << col+1 << *k << endl;
	possCols[*k].push_back(col);
      }
    }
   }
    for(int number=1; number<=9; number++){
      if(possCols[number].size()==1){//only a single appearance of the number in the row
	int column=possCols[number][0];//the only column where a number can go
	board[row][column]=number;//set board to the value of the number
	possible[row][column].clear();//clear the possible vector and insert number into it
        possible[row][column].push_back(number);
      }
    }
    //reset posscols
    for(int i=0; i<possCols.size(); i++) possCols[i].clear();
  }
}

//this function implements the singleton method on a column
template <typename T>
void Puzzle<T>::singletonCol(){
  //declare and initialize
  //possRows is a 2d vector: 1st dimension is the number 0-9,
  //2nd dimension stores the rows in which the number appears
  vector<int> temp;
  vector< vector<int> > possRows;
  for(int i=0; i<=9; i++) possRows.push_back(temp);//initialize possRows
  vector<int>::iterator k;

  //do singleton for all cols 
  for(int col=0; col<9; col++){
   for(int row=0; row<9; row++){//this loops through the rows of a single column
    for(k=possible[row][col].begin(); k != possible[row][col].end(); ++k){//loops through all possible values for cell (row,col)
      if(board[row][col]==0){//if the number isn't already filled in on the board
	//stores all of the columns in which a number can go
	possRows[*k].push_back(row);
      }
    }
   }
    for(int number=1; number<=9; number++){
      if(possRows[number].size()==1){//only a single appearance of the number in the column 
	int rowNumber=possRows[number][0];//the only row where a number can go
	board[rowNumber][col]=number;//set board to the value of the number
	possible[rowNumber][col].clear();//clear the possible vector and insert number into it
        possible[rowNumber][col].push_back(number);
      }
    }
    //reset possRows
    for(int i=0; i<possRows.size(); i++) possRows[i].clear();
  }
}

//this function implements the singleton method on a minibox
template <typename T>
void Puzzle<T>::singletonBox(){
  //declare and initialize
  //possRows is a 2d vector: 1st dimension is the number 0-9,
  //2nd dimension stores the rows in which the number appears
  vector<int> temp;
  vector< vector<int> > possRows, possCols;
  for(int i=0; i<=9; i++){ 
    possRows.push_back(temp);//initialize possRows
    possCols.push_back(temp);//initialize possCols
  }
  vector<int>::iterator k;

  //the first two loops loop through the 9 total miniboxes
  for(int y=0; y<=6; y+=3){
  for(int x=0; x<=6; x+=3){
  //these two loop through values within each minibox
  for(int row=y; row<y+3; row++){
    for(int col=x; col<x+3; col++){
      for(k=possible[row][col].begin(); k != possible[row][col].end(); ++k){//loops through all possible values for cell (row,col)
        if(board[row][col]==0){//if the number isn't already filled in on the board (if it is, then don't put it into the possible array
	  //stores all of the row/column pairs in which a number can go
	  possRows[*k].push_back(row);
	  possCols[*k].push_back(col);
        }
      }
    }
  }
    for(int number=1; number<=9; number++){
      if(possRows[number].size()==1 && possCols[number].size()==1){//only a single appearance of the number in the row and column 
	int rowNumber=possRows[number][0];//the only row where a number can go
	int colNumber=possCols[number][0];//the only column where a number can go
	board[rowNumber][colNumber]=number;//set board to the value of the number
	possible[rowNumber][colNumber].clear();//clear the possible vector and insert number into it
        possible[rowNumber][colNumber].push_back(number);
      }
    }
    //reset possRows and possCols
    for(int i=0; i<possRows.size(); i++) possRows[i].clear();
    for(int i=0; i<possCols.size(); i++) possCols[i].clear();
  }
  }
}

//this function checks if a number can be added to the puzzle in a specified spot
template <typename T>
int Puzzle<T>::check(int row, int col, T element){
  //check if that spot is already filled
  if(board[row][col]!=0){//the spot is filled
    return 1;
  } 
  //check the row to see if the element already exists
  else if(checkRow(row, element)){
    return 2;
  }
  //check the column to see if the element already exists
  else if(checkCol(col, element)){
    return 3;
  }
  //check the miniBox to see if the element already exists
  else if(checkBox(row, col, element)){
    return 4;
  }
  else { //The value can be placed here with no errors
    return 0;
  }  
}  

//this function is only useful for within the play function, uses 
template <typename T>
void Puzzle<T>::insert(int row, int col, T element){
  switch(check(row,col,element)){
    case 0://all set, insert the value
    	board[row][col]=element;
    	print();
	break;
    case 1://there is already a numebr here
	cout << "That spot already has a number in it. Please select a different place." << endl;
	break;
    case 2://already in the row
	cout << "The element " << element << " is already in row " << row << "." << endl;
	break;
    case 3://already in the column
	cout << "The element " << element << " is already in column " << col << "." << endl;
	break;
    case 4://already in the minibox
	cout << "The element "<<element<<" is already in the mini box with top left coordinates: ";
    	cout << "(" << row-row%3 << "," << col-col%3 << ")." << endl;
	break;
  }
}		

//removes an element from the board (only non-initial elements)
template <typename T>
int Puzzle<T>::remove(int row, int col){
  //check if initial has that spot filled (you can only remove spots initially 0)
  if(initial[row][col]==0){
    board[row][col]=0;
    print();
    return 0;
  } else {
    cout << "You cannot delete this element. It was part of the initial board." << endl;
    return 1;
  }
} 

//this resets the board to the initial board
template <typename T>
void Puzzle<T>::reset(){
  board=initial;
}

//checks if the board is full of nonzero values
template <typename T>
int Puzzle<T>::unfilled(){
  //number increments every time a new 0 is found on the board
  int number=0;

  //loop through both dimensions of the vector
  for(int i=0; i<board.size(); i++){
    for(int j=0; j<board[i].size(); j++){
      if(board[i][j]==0){
	number++;
      }
    }
  }
  return number;    
}

//checks if the board is full of nonzero values
template <typename T>
int Puzzle<T>::isFull(){
  int full=0;
  if(unfilled()==0) full=1;
  return full;    
}

template <typename T>
int Puzzle<T>::checkRow(int row, T element){
  //check is a variable to keep track if the element is found in the row
  int check = 0;//will be changed to 1 if the number is found in the row

  for(int i=0; i<board[row].size(); i++){
    if(board[row][i]==element){//the element is already in the desired row
	check = 1;
    }
  }
  return check;
}

template <typename T>
int Puzzle<T>::checkCol(int col, T element){
  //check is a variable to keep track if the element is found in the column
  int check = 0;//will be changed to 1 if the number is found in the column

  for(int i=0; i<board.size(); i++){
    if(board[i][col]==element){//the element is already in the desired column
	check = 1;
    }
  }
  return check;
}

template <typename T>
int Puzzle<T>::checkBox(int row, int col, T element){
  //check is a variable to keep track if the element is found in the box
  int check = 0;//will be changed to 1 if the number is found in the box

  //define top left values to make indexing standard
  //x and y are the column and row (respectively) of the mini box to be indexed through
  int x=col-col%3;
  int y=row-row%3;

  for(int i=y; i<y+3; i++){
    for(int j=x; j<x+3; j++){
      if(board[i][j]==element){//the element is already in the desired column
	check = 1;
      }
    }
  }
  return check;
}


//The explicit instantiation
template class Puzzle<int>; 
