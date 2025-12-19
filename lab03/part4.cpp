/***********************************************************
* Program reads user's birthdate and determines how many
* days older Maj Hawkins is than the user.  The date is not my real
* birthday, because using my real birthday would be PII.
***********************************************************/
#include "Date.h"
#include <iostream>
using namespace std;
int main() {
  // Set my "birthday" and read yours
  Date MyBD(5,25,1979); // May 25, 1979 is day the movie "Alien" was released
  Date YrBD;
  cout << "What was your birth date? ";
  YrBD.readIn(cin);

  // If I'm older, compute by how many days and print it
  if (YrBD.before(MyBD))
    cout << "You're older than I!" << endl;
  else {
    int count = 0;
    for(Date T = MyBD; T.before(YrBD); T.inc())
      count++;
    cout << "I'm " << count << " days older than you!" << endl;
  }

  return 0;
}