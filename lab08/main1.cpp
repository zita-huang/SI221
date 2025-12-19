#include <iostream>
#include <string>
#include "ArrayStuff.h"
using namespace std;

int main() {
  // Read 5 strings
  string A[5];
  cout << "Enter 5 strings: ";
  for(int i = 0; i < 5; i++)
    cin >> A[i];

  // Print alphabetically smallest
  cout << "The alphabetically smallest is \""
       << minimum(A,5) << "\"." << endl;

  return 0;
}
