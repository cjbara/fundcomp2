//Cory Jbara - Fund Comp 2 - Prelab
//This is the header file for the Mortgage class

class Mortgage {
 public:
  Mortgage();				//default constructor
  Mortgage(double,double,double);	//non-default constructor
  void credit(double);
  double getPrincipal();
  void amortize ();

 private:
  double principal;	//initial money owed
  double rate;		//yearly interest rate
  double payment;	//monthly payment
};
