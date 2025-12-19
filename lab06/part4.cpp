/****
Name: Zita Huang
Lab 06, Part 4
****/
#include "TradQueue.h"
#include <iostream>
#include <ctime>
using namespace std;

class Midshipman {
private:
    int arrivalTime;
    int haircutTime;

public:
    Midshipman() : arrivalTime(0), haircutTime(0) {}
    Midshipman(int arrival, int haircut) : arrivalTime(arrival), haircutTime(haircut) {}

    int getArrivalTime() const { return arrivalTime; }
    int getHaircut() const { return haircutTime; }
};

class Barber {
private:
    bool busy;
    Midshipman currentMid;
    int startTime;

public:
    Barber() : busy(false), startTime(0) {}

    bool isBusy() const { return busy; }

    void work(Queue<Midshipman>& line, int currentTime) {
        // Check if current haircut finished
        if (busy) {
            if (currentTime - startTime >= currentMid.getHaircut()) {
                busy = false;
            }
        }

        // If barber is free, take next Midshipman
        if (!busy && !line.isEmpty()) {
            currentMid = line.peek();
            line.dequeue();
            busy = true;
            startTime = currentTime;

            int waitTime = currentTime - currentMid.getArrivalTime();
            cout << "Midshipman arrived at " << currentMid.getArrivalTime()
                 << " and waited " << waitTime << endl;
        }
    }
};

int main() {
    Queue<Midshipman> incoming;
    Queue<Midshipman> line;

    int arrival, duration;
    // Input: arrival time and haircut duration
    while (cin >> arrival >> duration) {
        Midshipman m(arrival, duration);
        incoming.enqueue(m);
    }

    int startTime = time(0);
    Barber barber;

    while (!incoming.isEmpty() || !line.isEmpty() || barber.isBusy()) {
        int currentTime = static_cast<int>(time(0) - startTime);

        // Move Midshipmen from incoming to line when their time arrives
        if (!incoming.isEmpty()) {
            Midshipman next = incoming.peek();
            if (next.getArrivalTime() <= currentTime) {
                incoming.dequeue();
                line.enqueue(next);
            }
        }

        // Barber processes line
        barber.work(line, currentTime);
    }

    return 0;
}
