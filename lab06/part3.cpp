/****
Name: Zita Huang
Lab 06, Part 3
****/
#include "TradQueue.h"
#include <iostream>
#include <ctime>
using namespace std;

class Midshipman {
private:
    int arrivalTime;
    int haircut;

public:
    Midshipman() : arrivalTime(0), haircut(0) {}
    Midshipman(int arrival, int duration) : arrivalTime(arrival), haircut(duration) {}

    int getArrivalTime() const {
        return arrivalTime;
    }
    int getHaircut() const {
        return haircut;
    }
};

int main() {
    Queue<Midshipman> incoming;
    Queue<Midshipman> line;

    int arrival, duration;
    while (cin >> arrival >> duration) {
        Midshipman m(arrival, duration);
        incoming.enqueue(m);
    }

    int startTime = time(0);

    while (!incoming.isEmpty()) {
        int currentTime = time(0) - startTime;
        Midshipman next = incoming.peek();

        if (next.getArrivalTime() <= currentTime) {
            incoming.dequeue();
            line.enqueue(next);
            cout << "Midshipman arrived at " << next.getArrivalTime()
                 << " with duration " << next.getHaircut() << endl;
        }
    }

    return 0;
}