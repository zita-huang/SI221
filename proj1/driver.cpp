/*************************************************************
** driver.cpp - this file defines main() for a program using
** the Back, Expenses, and Income modules to simulate 5 years
** of the finacial like of John Doe.  After the simulation,
** his bank balance is printed.
*************************************************************/
#include "bank.h"     // Bank interface
#include "expenses.h" // Expenses interface
#include "income.h"   // Income interface
#include "lottery.h"  //Lottery interface
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main( int argc, char * argv[]){
  /**************************************
  ** Initialization
  **************************************/
  // seed the random number generator
  srand(time(NULL));
  for(int i = 0; i < 1000; i++){ //go through 1000 times
    Bank B;
    Expenses E;
    Income I;
    Lottery L;
    initialize(B,1000);        // $1000 dollars initially
    initialize(E,1300,450,36); // $1300 rent, $450 car for 36 months
    initialize(I,32000);       // $32,000 a year pre-tax salary
    initialize(L,argc, argv);       //$10,000 for the lottery

  /**************************************
  ** Simulate 5 years & print balance
  **************************************/
    for(int m = 0; m < 5*12; m++){
      double exps = simulatemonth(E),
            incm = simulatemonth(I);
      withdraw(exps,B); // withdraw what you spend
      simulatemonth(B); // accrue month's interest
  
      //lottery simulate
      if(play(L, m)){
       int cost = L.tickets * 10;
       withdraw(cost, B);
      }
      double result = simulateLotto(L, m);
      if(result > 0){
        deposit(result, B);
        }
      deposit(incm, B);
      }
    cout << getbalance(B) << endl;
    }
}

