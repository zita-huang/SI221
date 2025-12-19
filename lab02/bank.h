/****************************************************
 **
 ** Interface for Bank module.  The rules of the bank:
 ** 1)  You can go into the red, i.e. negative balance!
 ** 2)  Interest rate for positive balance is:
 **     a) 3% Annual rate compounded monthly,
 **     b) plus 0.25% for every $1,000 in your account
 **     c) to a maximum of 5%
 ** 3)  Interest for a negative balance is:
 **     a) 5% Annual rate compounded monthly,
 **     b) plus 0.5% for every $1,000 in your account
 **     c) there is no ceiling!
 **
 ****************************************************/
// Definition of class Bank.  For now a bank consists
// only of a balance, but we may want to change that!
class Bank {
 public:
  double balance;
};

// Initializes Bank - balance is set to Amt
void initialize(Bank &B, double Amt);

// Returns the balance in bank B
double getbalance(Bank B);

// Simulates one month (interest accrues)
void simulatemonth(Bank &B);

// Simulates a deposit of Amt dollars in Bank B
void deposit(double Amt, Bank &B);

// Simulates a withdrawal of Amt dollars in Bank B
void withdraw(double Amt, Bank &B);
