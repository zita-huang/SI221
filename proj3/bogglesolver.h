#include "boggle.h"
#include <fstream>
#include <set>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

//class of BoggleSolver
class BoggleSolver {
public:
    BoggleSolver(string filename);
    set<string> solve(Boggle boggle);

private:
    set<string> dictionary;
    set<string> findWords(string soFar, int row, int col,
                          const vector<vector<char>>& letters,
                          vector<vector<bool>>& used); //hint given by teacher

    bool hasPrefix(const string& prefix);
};