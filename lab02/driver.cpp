/*************************************************************
** driver.cpp - this file defines main() for a program using
** the Back, Expenses, and Income modules to simulate 5 years
** of the finacial like of John Doe.  After the simulation,
** his bank balance is printed.
*************************************************************/
#include "bank.h"     // Bank interface
#include "expenses.h" // Expenses interface
#include "income.h"   // Income interface
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main( int argc, char * argv[] ){

  /**************************************
  ** Initialization
  **************************************/
  // seed the random number generator
  if (argc > 1) srand(atoi(argv[1])); //use command line argument if provided
  else srand(time(NULL)); //use system time otherwise

  Bank B;
  Expenses E;
  Income I;
  initialize(B,1000);        // $1000 dollars initially
  initialize(E,1300,450,36); // $1300 rent, $450 car for 36 months
  initialize(I,32000);       // $32,000 a year pre-tax salary

  /**************************************
  ** Simulate 5 years & print balance
  **************************************/
  for(int m = 0; m < 12*5; m++){
    double exps = simulatemonth(E),
           incm = simulatemonth(I);
    withdraw(exps,B); // withdraw what you spend
    simulatemonth(B); // accrue month's interest
    deposit(incm,B);  // deposit what you've earned
    cout << getbalance(B) << endl;
  }
  cout << getbalance(B) << endl;
}
