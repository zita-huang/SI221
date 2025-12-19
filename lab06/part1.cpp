/****
Name: Zita Huang
Lab 06, Part 1
****/
#include <iostream>
#include "TradQueue.h"
using namespace std;

int main(){
    Queue<double> incoming;
    for(double x; cin >> x; x++){
        incoming.enqueue(x);
    }
    while(!incoming.isEmpty()){
        cout << incoming.dequeue() << endl;
    }
    return 0;
}