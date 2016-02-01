#include <iostream>
using namespace std;

int main(){

 double pi;
 int terms=0;		//number of total terms (entered by user)
 int termNumber=1;	//iterator for terms
 
 /* This loop acquires number of terms to use for pi's estimate */
 while(1){ 
  cout << "How many terms will we use? ";
  cin >> terms;
 
  if(!(terms>=2)){
   cout << "Error, number of terms must be >=2" << endl;
  } else {break;}
 }
 
 int numerator=4;	//Numerator (always 4 or -4)
 double denominator=1;	//denominator must be double (increases by 2 each term)

 for(int i=1;i<=terms;i++){
  pi += (numerator/denominator);
  cout << "Estimate after " << i << " terms: "; 
  cout.precision(5);	//sets output precision to 4 decimal places
  cout << pi << endl;	//prints value of pi

  numerator *= -1;	//Numerator becomes negative of last term
  denominator += 2;	//Denominator increases by 2 each term
 }
 return 0;
}

