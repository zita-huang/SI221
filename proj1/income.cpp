/********
Primary: Zita Huang
Secondary: Braylon Stafford
Income Implemention
********/
#include <iostream>
#include <cstdlib>
#include "income.h"
using namespace std;

//initializes the income to the annual salary
//S is the annual income
void initialize(Income &I, double S){
    I.annualSalary = S;
}

//simulate each month
double simulatemonth(Income &I){
    double preTax = I.annualSalary/12; //get monthly salary
    double tax;
    double postTax;
    double raise;
    double unemploymentDinero;
    bool employed = true;
    if(employed == true){
        if((rand() % 100 + 1) < 3){
            employed = false;
        }
        if(I.annualSalary < 20000){
            if((rand() % 100 + 1) < 10){
                raise = (preTax * 0.02) + preTax;
                tax = preTax * 0.10;
                postTax = preTax - tax;
                preTax += raise;
            }
            else{
                tax = preTax * 0.10;
                postTax = preTax - tax;
            }
        }
        if((20000 < I.annualSalary) && I.annualSalary< 40000){
            if((rand() % 100 + 1) < 10){
                raise = (preTax * 0.02) + preTax;
                tax = raise * 0.20;
                postTax = preTax - tax;
                preTax += raise;
            }
            else{
                tax = preTax * 0.20;
                postTax = preTax - tax;
            }
        }
        if(I.annualSalary > 40000){
            if((rand() % 100 + 1) < 10){
                raise = (preTax * 0.02) + preTax;
                tax = preTax * 0.30;
                postTax = preTax - tax;
                preTax += raise;
            }
            else{
                tax = preTax * 0.30;
                postTax = preTax - tax;
            }
        }
    }
    if(employed == false){
        preTax = 0;
        unemploymentDinero = 300;
        if((rand() % 100 + 1) < 50){
            employed = true;
        }
        else{
            unemploymentDinero += 300;
        }
    }
    return postTax;
}