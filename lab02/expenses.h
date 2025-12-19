/****************************************************
 **
 ** Interface for Expenses module.  Rules are:
 ** 1)  Expenses for one month are the carPmt + rent
 ** 2)  Once the car is paid off, it' not an expense!
 ** 3)  Every month there is a 20% chance you have to
 **     fork over $800 for car repairs - once the car
 **     is paid off that jumps to a 40% chance!
 **
 ****************************************************/
class Expenses {
 public:
  double rent;
  double carPmt;
  int carMonthsLeft;
};

// Initializes the expenses situation R is the rent amount,
// C the car payment amount, and M the months left on the car
void initialize(Expenses &E, double R, double C, int M);

// Simulates 1 month and returns expenses for that month
double simulatemonth(Expenses &E);
