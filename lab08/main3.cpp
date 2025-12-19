#include <iostream>
#include "part3.h"
using namespace std;

int main() {
  // Read in doubles
  cout << "Enter values terminated by \";\" ";
  Averager A;
  double x; 
  while (cin >> x)
    A.add2collection(x);


  cout << "The average was "
       << A.average() << endl;

  return 0;
}
