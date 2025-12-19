/****************************************************
 **
 ** Interface for Income module.  Rules are:
 ** 1)  Your monthly will be 1/12 of your annual income
 ** 2)  Each month you are employed there is a 2%
 **     you will lose your job at the end of the month!
 ** 3)  Each month you are employed (and not fired),
 **     there is a 10% chance you'll get a 2% raise
 **     at the end of the month;
 ** 4)  Each month you are unemployed there is a 50%
 **     chance you'll find a job at the end of the
 **     month.  Unfortunately, you have no income while
 **     unemployed!
 ** 6)  Taxes are taken out of each check.  Your rate
 **     (i.e. how much is taken out for taxes) is
 **     determined by your annual salary. 10% for under
 **     $20,000, 20% for between $20,000 and $40,000
 **     and 30% for $40,000 and above.
 **
 ****************************************************/

class Income {
 public:
  double annualSalary;
  bool employed;
};

// Initialize Income I to an annual salary of S dollars
void initialize(Income &I, double S);

// Simulate one month of income and return the amount earned
double simulatemonth(Income &I);
