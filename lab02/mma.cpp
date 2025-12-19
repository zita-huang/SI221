/************************************************
 * This program reads numbers from standard input
 * (i.e. through cin), computes min, max, and
 * average of the numbers, and prints these
 * values.
 ************************************************/
#include <iostream>
using namespace std;

int main() {
  // Read 1st number & initialize values
  double next, min, max, sum;
  cin >> next;
  min = max = sum = next;
  int count = 1;

  // Read subsequent numbers and update min, max, sum and count
  while(cin >> next) {
    sum += next;
    count ++;
    if (next < min)
      min = next;
    if (next > max)
      max = next;
  }

  // Print results
  cout << "min = " << min << endl;
  cout << "max = " << max << endl;
  cout << "avg = " << sum/count << endl;

  return 0;
}