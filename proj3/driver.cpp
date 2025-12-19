#include "bogglesolver.h"
#include <vector>
#include <iostream>
#include <ctime>
using namespace std;

int main(){
  srand (time(NULL));

  clock_t time = clock();
  Boggle boggle("AAIAEENABENNETNTLTHLYWPTU");  //specific boggle for testing
  BoggleSolver genius("american-english.txt");
  set<string> answers = genius.solve(boggle);
  time = clock() - time;

  cout << boggle << endl << endl;

  unsigned int score = 0;
  cout << "Found the following " << answers.size() << " words:" << endl;
  unsigned int count = 0;
  for (string s : answers){
    unsigned int wordLen = s.length();
    if(wordLen >= 8) score += 11;
    else if (wordLen == 7) score += 5;
    else if (wordLen == 6) score += 3;
    else if (wordLen == 5) score += 2;
    else if (wordLen >= 3) score += 1;
    else ;
    cout << s << " ";
    if (++count % 10 == 0) cout << endl;
  }
  cout << endl;
  cout << "Elapsed Time: " << (long double)time/CLOCKS_PER_SEC << " seconds" << endl;
  cout << "Score: " << score << endl;

  return 0;
}
