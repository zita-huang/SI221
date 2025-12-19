/****
Name: Zita Huang
Lab 06, Part 2
****/
#include <iostream>
#include <ctime>
#include "TradQueue.h"
using namespace std;

int main(){
    Queue<double> incoming;
    Queue<double> line;
    
    int x;
    while(cin >> x){
        incoming.enqueue(x);
    }
    int startTime = time(0);
    while(!incoming.isEmpty()){
        int currentTime = time(0) - startTime;
        int arrivalTime = incoming.peek();

        if(arrivalTime <= currentTime){
            incoming.dequeue();
            line.enqueue(arrivalTime);
            cout << "Midshipman arrived at " << arrivalTime << endl;
        }
    }

    return 0;
}