#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
  // Read & store currency names and exchange rates
  ifstream IN("rates.txt");

  /* 1. create new map object named Val that uses a string key and double value */

  string currency, shorthand;
  double valOfDollar;
  map<string, double> Val;
  while(IN >> currency >> valOfDollar >> shorthand){
    pair<string,double> KV(currency,valOfDollar);

    /* 2. add the new pair to your map */
    Val.insert(KV);
  }

  // Read amount, currency1 & currency2 and convert
  string curr1, curr2;
  double amt;
  while(cout << "Enter <amt> <curr1> <curr2>: ", cin >> amt >> curr1 >> curr2) {
    map<string,double>::iterator itr1 = Val.find(curr1);
    map<string,double>::iterator itr2 = Val.find(curr2);

    /* 3. What do we do now? Add code to determine whether both currencies were
     *    found and, if so, what the value of "amt" in "curr1" is in "curr2".
     *    Print results!
     */
    if(itr1 != Val.end()){
        if(itr2 != Val.end()){
            double math;
            math = ((*itr2).second/ (*itr1).second) * amt;
            cout << amt << " " << curr1 << " " << "is " << math << " " << curr2 << endl;
        }
    }
    else
        cout << "Currency not found!" << endl;
  }

  return 0;
}