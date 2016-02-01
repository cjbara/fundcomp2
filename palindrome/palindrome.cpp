//Cory Jbara - Lab4 - Part1 - Vector palindromes
//This program checks if two vectors are palindromes
//The function isPalindrome checks if they are, the rest is a driver

#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;

int isPalindrome(vector<int>);

int main(){

  int array1[7]={2,3,4,5,4,3,2};//this is a palindrome
  int array2[7]={3,4,4,4,4,5,6};//this is not a palindrome

  //this declares two vectors, both filled with arrays
  //vec1 is a plaindrome, vec2 is not a palindrome
  vector<int> vec1(array1, array1+7);
  vector<int> vec2(array2, array2+7);

/* Alternate way of filling the vectors, I started with this but moved to the initialize and 
 * fill at the same time method.
  //fill the vectors
  vec1.push_back(2);
  vec1.push_back(3);
  vec1.push_back(4);
  vec1.push_back(5);
  vec1.push_back(4);
  vec1.push_back(3);
  vec1.push_back(2);

  vec2.push_back(2);
  vec2.push_back(3);
  vec2.push_back(4);
  vec2.push_back(7);
  vec2.push_back(6);
  vec2.push_back(3);
  vec2.push_back(3);
  */
  isPalindrome(vec1);
  isPalindrome(vec2);
}

int isPalindrome(vector<int> forward){

  vector<int> backward;
/* This method works too, but I wanted to try using iterators
  backward=forward;
  reverse(backward.begin(), backward.end());
*/  
  vector<int>::const_reverse_iterator i;
  //Reverse the order of forward and store it into backward
  for(i = forward.rbegin(); i != forward.rend(); ++i){
    backward.push_back(*i);
  }

  vector<int>::const_iterator j;
  for(j=forward.begin(); j != forward.end(); ++j){
    cout << *j << " ";
  }

  cout << endl;
  for(int i=0; i<backward.size(); ++i){
    cout << backward[i] << " ";
  }
  cout << endl;

  //if the two vectors are the same, return 1, else return 0
  if(forward==backward){
	cout << "The vector you entered is a palindrome!" << endl;
	return 1;
  } else {
	cout << "The vector you entered is not a palindrome." << endl; 
	return 0;
  }
return 1;
}
