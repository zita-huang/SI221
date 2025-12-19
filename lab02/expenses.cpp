/**
Primary: Braylon Stafford
Secondary: Zita Huang
Expenses implementation
**/

#include <iostream>
#include <cstdlib>
using namespace std;
#include "expenses.h"

// Initializes the expenses situation R is the rent amount,
// C the car payment amount, and M the months left on the car
void initialize(Expenses &E, double R, double C, int M)
{
    E.rent = R;
    E.carPmt = C;
    E.carMonthsLeft = M; 
}

// Simulates 1 month and returns expenses for that month
double simulatemonth(Expenses &E)
{
    double Tot = 0;
    if(E.carMonthsLeft > 0)
    {
        Tot += E.carPmt;
        E.carMonthsLeft--;
        if ((rand()%10 + 1 <3)) 
            Tot += 800;
    }
    else
    {
        if ((rand()%10 + 1 <5))
            Tot += 800;
    }

    return Tot += E.rent;
}