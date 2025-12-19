#include "boggledie.h"
#include <stdlib.h>
#include <iostream>
using namespace std;BoggleDie::BoggleDie(string f) : faces(f), faceup(0) {}

//roll each die face
void BoggleDie::roll(){
    faceup = rand() % 6;
}

//return the value of the face
char BoggleDie::get() const{
    return faces[faceup];
}

//overload the operator for the correct faces in the die
ostream& operator<<(ostream& out, const BoggleDie& d){
    char face = d.get();
    //if the character of the die is Q then it must be QU
    if(face == 'Q'){
        cout << 'Q' << 'U';
    }
    else{
        cout << face;
    }
    return cout;
}