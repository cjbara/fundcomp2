#include <iostream>
#include <string>
using namespace std;

int main()
{
  //size is 7 letters long
  int size = 7;
  //start by permuting all combinations, including 3 letters in a row
  char word[size] = {"AAAAAAA"};

  long int count=0;//counts the number of permutations
  int threeConsec = 0;//flag for 3 consecutive letters
  
  //Each loop will start at A and go to Z, and will only increment the count when there aren't 
  //3 consecutive identical letters
  for(char c0='A'; c0<='Z'; c0++){
    word[0] = c0;
    for(char c1='A'; c1<='Z'; c1++){
      word[1] = c1;
      for(char c2='A'; c2<='Z'; c2++){
	word[2] = c2;
        for(char c3='A'; c3<='Z'; c3++){
	  word[3] = c3;
          for(char c4='A'; c4<='Z'; c4++){
	    word[4] = c4;
    	    for(char c5='A'; c5<='Z'; c5++){
	      word[5] = c5;
      	      for(char c6='A'; c6<='Z'; c6++){
		word[6] = c6;
		//if you have 3 consecutive letters, don't increment count
		if(word[0] == word[1] && word[1] == word[2]) threeConsec = 1;
		else if(word[1] == word[2] && word[2] == word[3]) threeConsec = 1;
		else if(word[2] == word[3] && word[3] == word[4]) threeConsec = 1;
		else if(word[3] == word[4] && word[4] == word[5]) threeConsec = 1;
		else if(word[4] == word[5] && word[5] == word[6]) threeConsec = 1;
		else threeConsec = 0;

		//if there aren't three consecutive, increment the count
		if(!threeConsec){ count++; }
	      }
	    }
	  }
	}
      }
    }
  }
  
  cout << "There are " << count << " 7 letter words without three of the same consecutive letters." << endl;
}
