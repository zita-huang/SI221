#include <iostream>
#include <cstdlib>
#include <cmath>
#include "lottery.h"
using namespace std;

Lottery::Lottery(){
    lottoMoney = 0;
    win = false;
    frequency = "never";
    pot = 10000;
    tickets = 0;
    minPot = 0;
}
//initalize all variables within the function
void initialize(Lottery &L, int argc, char* argv[]){
    L.frequency = "never";
    L.tickets = 0;
    L.minPot = 0;
    L.lottoMoney = 0;
    L.pot = 10000;
    L.win = false;

    for(int i = 1; i < argc; i++){
        std::string arg = argv[i];
        //read in the inputed argument and compare for frequency
        if(arg == "-never"){
            L.frequency = "never";
        }
        else if(arg == "-monthly"){
            L.frequency = "monthly";
        }
        else if(arg == "-semiannual"){
            L.frequency = "semiannual";
        }
        else if(arg == "-bimonthly"){
            L.frequency = "bimonthly";
        }
        else if(arg == "-annual"){
            L.frequency = "annual";
        }
        else if(arg == "-minPot"){
            if(i + 1 < argc){
                L.frequency = "minPot";
                L.minPot = atoi(argv[i++]);
            }
        }
        //read in the tickets and amount bought
        else if(arg == "-tickets"){
            if(i + 1 < argc){
                L.tickets = atoi(argv[i++]);
            }
        }
    }
}

bool play(const Lottery &L, int month){
    if(L.frequency == "monthly"){
        return true;
    }
    if(L.frequency == "bimonthly"){
        return (month % 2 == 1); //bimonthly calculation of math
    }
    if(L.frequency == "semiannual"){
        return (month % 6 == 1); //semiannual math calculation
    }
    if(L.frequency == "annual"){
        return (month % 12 == 1); //annual math calculation
    }
    if(L.frequency == "minPot"){
        return L.pot >= L.minPot; //minpot calculation
    }

    return false;
}

//function to simulate the lottery
double simulateLotto(Lottery &L, int month){
    double lottoEarnings = 0;
    bool win = false;

    int notENS = rand() % 2;
    if(notENS == 1){
        bool ENS = false;
        for(int i = 0; i < L.tickets; i++){
            int r = rand() % 2000; //1 in 2000 chance of winning
            if(r == 0){
                ENS = true;
                break;
            }
        }
        if(ENS){
            lottoEarnings = L.pot;
            L.lottoMoney += lottoEarnings;
            L.win = true;
        }
        L.pot = 10000;
    }
    else{
        L.pot += 10000;
    }
     

    return lottoEarnings;
}