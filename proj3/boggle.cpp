#include "stdlib.h"
#include "boggle.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;

//define all the die combinations
const string Boggle::Boggle_face[25] = {
    "AAAFRS", "AAEEEE", "AAFIRS", "ADENNN", "AEEEEM",
    "AEEGMU", "AEGMNN", "AFIRSY", "BJKQXZ", "CCENST",
    "CEIILT", "CEILPT", "CEIPST", "DDHNOT", "DHHLOR",
    "DHLNOR", "DHLNOR", "EIIITT", "EMOTTT", "ENSSSU",
    "FIPRSY", "GORRVW", "IPRRRY", "NOOTUW", "OOOTTU"
};

Boggle::Boggle(){
    for(int i = 0; i < 25; i++){
        dice.push_back(BoggleDie(Boggle_face[i]));
    }
    roll();
}

//function to roll the board
void Boggle::roll(){
    for(int i = 0; i < dice.size(); i++){
        dice[i].roll();
    }
    random_shuffle(dice.begin(), dice.end()); //shuffle the boggle board
}

//input the string of the board, mainly for test.cpp/driver.cpp
Boggle::Boggle(string faces){
    for(int i = 0; i < 25; i++){
        string singleFace(1, faces[i]);
        dice.push_back(BoggleDie(singleFace + singleFace + singleFace +
                                 singleFace + singleFace + singleFace));
    }
}

//overload the operator so that the board can be printed out
//used the advanced board, while also outputing the correct boggle board
ostream& operator<<(ostream& out, const Boggle& board){
    out << "\u256d";
    for(int i = 0; i < 5; i++){
        out << "\u2500\u2500\u2500\u2500";
        if(i < 4){
            out << "\u252c";
        }
    }
    out << "\u256e" << endl;
    
    for(int row = 0; row < 5; row++){
        out << "\u2502";
        for(int col = 0; col < 5; col++){
            out << " ";
            char face = board.dice[row * 5 + col].get();
            if(face == 'Q'){
                out << "Qu";
            }
            else{
                out << " " << face;
            }
            out << " \u2502";
        }
        out << endl;  
        
        if(row < 4){
            out << "\u251c";
            for(int i = 0; i < 5; i++){
                out << "\u2500\u2500\u2500\u2500";
                if(i < 4){
                    out << "\u253c";
                }
            }
            out << "\u2524" << endl;
        }
    }
    
    out << "\u2570";
    for(int i = 0; i < 5; i++){
        out << "\u2500\u2500\u2500\u2500";
        if(i < 4){
            out << "\u2534";
        }
    }
    out << "\u256f";
    
    return out;
}
