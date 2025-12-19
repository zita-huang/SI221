#include "stdlib.h"
#include "boggledie.h"
#include <vector>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

//class for Boggle 
class Boggle{
public:
    Boggle();
    Boggle(string);
    void roll();
    friend ostream& operator<<(ostream& out, const Boggle& board);
    friend class BoggleSolver;
private:
    vector<BoggleDie> dice;
    static const string Boggle_face[25];
};