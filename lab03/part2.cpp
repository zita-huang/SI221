#include "Point.h"
#include <iostream>
using namespace std;

int main(){
  // Declare points and prompt user for input
    cout << "Enter points A and B: \n";
    Point A,B;

  // Read in the points using the member function
    A.readIn(cin);
    B.readIn(cin);

  // NEW: Print the points using the writeOut function
    cout << "Point A is: ";
    A.write0ut(cout);
    cout << endl;

    cout << "Point B is: ";
    B.write0ut(cout);
    cout << endl;

  // NEW: Compute the midpoint and print using the writeOut function
    cout << "The midpoint between A and B is: ";
    midpoint(A,B).write0ut(cout);
    cout << endl;

  // NEW: Compute & print distance between the points
    cout << "The distance between A and B is: " << distance(A,B) << endl;


  return 0;
}