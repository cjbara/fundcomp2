
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

//this function checks if a number can be added to the puzzle in a specified spot
template <typename T>
int Puzzle<T>::insert(int row, int col, T element){
  //decrement the variables for proper indexing
  row--;
  col--;
  
  char input;//used to make sure user wants to overwrite, etc.
  //check if that spot is already filled
  if(board[row][col]!=0){//the spot is filled
    cout << "That spot already has a number in it. Please select a different place." << endl;
    return 1;
  } 
  //check the row to see if the element already exists
  else if(checkRow(row, element)){
    cout << "The element " << element << " is already in row " << row+1 << "." << endl;
    return 2;
  }
  //check the column to see if the element already exists
  else if(checkCol(col, element)){
    cout << "The element " << element << " is already in column " << col+1 << "." << endl;
    return 3;
  }
  //check the miniBox to see if the element already exists
  else if(checkBox(row, col, element)){
    cout << "The element " << element << " is already in the mini box with top left coordinates: ";
    cout << "(" << row-row%3+1 << "," << col-col%3+1 << ")." << endl;
    return 4;
  }
  else {
    board[row][col]=element;
    print();
    return 0;
  }  
}  

template <typename T>
int Puzzle<T>::remove(int row, int col){
  //decrement the variables for proper indexing
  row--;
  col--;
  
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
int Puzzle<T>::isFull(){
  //full is updated to 0 if the board is not full
  int full=1;

  //loop through both dimensions of the vector
  for(int i=0; i<board.size(); i++){
    for(int j=0; j<board[i].size(); j++){
      if(board[i][j]==0 || board[i][j]=='0'){
	full=0;
      }
    }
  }
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
template class Puzzle<char>;
