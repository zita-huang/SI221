#include <stdlib.h>
#include <iostream>
using namespace std;

//class for BoggleDie
class BoggleDie{
public: 
    BoggleDie(string f);
    void roll();
    char get() const;
    friend ostream& operator<<(ostream& cout, const BoggleDie& d);

private:
    string faces;
    int faceup;
};