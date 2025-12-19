#include <iostream>
#include "List.h"
#include "ListStuff.h"
using namespace std;

int main() {
  // Read doubles
  cout << "Enter doubles terminated with a \";\" ";
  List<double> L;
  double x;
  while(cin >> x)
    L.add2back(x);

  // Print smallest
  cout << "The smallest is "
       << minimum(L) << "." << endl;

  return 0;
}
