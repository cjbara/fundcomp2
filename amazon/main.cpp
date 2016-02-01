#include "Package.h"
#include "TwoDay.h"
#include "Overnight.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  
  cout << setprecision(2) << fixed;
  
  //This driver program for part 2 prints out the contents of the two derived classes
  //extra fee is 5, weight is 50 ounces, and price per ounce is .25
  TwoDay two(5,"Cory", "Jbara","375 Angela","46556",50,.25);
  cout << endl << "The values of the TwoDay object are: " << endl;
  two.print();

  //extra fee per ounce is $.55, weight is 40, price .35
  Overnight over(.55,"Cory", "Jbara","123 ND Ave.","46556",40,.35);
  cout << endl << "The values of the Overnight object are: " << endl;
  over.print();
  

  //part 3 has six or more different derived classes
  //Start by declaring this is part 3
  cout << endl << "PART 3" << endl;

  //create the six new packages, three of each derived class
  TwoDay two1(1,"John", "Smith","12 Park Parkway","46556",50,.25); 
  TwoDay two2(2,"Joan", "Johnson","3489 Tessla Lane","47394",15,.15);
  TwoDay two3(12,"Vince", "Hart","243 Angela","32456",170,.22);

  Overnight over1(.55,"Cory", "Jbara","123 ND Ave.","46556",40,.35);
  Overnight over2(.37,"CJ", "Johns","226 Petes Ave.","46556",12,.23);
  Overnight over3(.67,"Henry", "Henrys","447 Eddy St.","46556",31,.11);

  //create array of pointers to package 
  Package *packagePtr[6];
  
  //set array to the six derived objects
  packagePtr[0] = &two1;
  packagePtr[1] = &two2;
  packagePtr[2] = &two3;
  packagePtr[3] = &over1;
  packagePtr[4] = &over2;
  packagePtr[5] = &over3;
  
  //initialize totalCost to 0
  double totalCost=0;

  //loop through the array and print out the cost of each package, then add the cost to the total
  for(int i=0; i<6; i++){
    cout << "Package number " << i+1 << " costs $" << packagePtr[i]->calcCost() << endl;
    totalCost += packagePtr[i]->calcCost();
  }

  //print out the total cost
  cout << "The total cost for the 6 packages is $" << totalCost << endl << endl;
}
