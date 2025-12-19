/******************************
 * template code for part1.cpp
******************************/
#include "Point.h"
#include <iostream>
#include <cmath>
using namespace std;

int main(){
  // Declare points and prompt user for input
    cout << "Enter points A and B: \n";
    Point A,B;

  // Read in the points using the member function
    A.readIn(cin);
    B.readIn(cin);

  // Print the points using member "getter" functions
    cout << "Point A is: (" << A.get_x() << ","
         << A.get_y() << "," << A.get_z() << ")" << endl;
    cout << "Point B is: (" << B.get_x() << ","
         << B.get_y() << "," << B.get_z() << ")" << endl;

  // Compute & print the midpoint
    Point M = midpoint(A, B);

    cout << "The midpoint between A and B is: ("
         << M.get_x() << "," << M.get_y() << ","
         << M.get_z() << ")" << endl;

  return 0;
}