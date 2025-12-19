#include "bogglesolver.h"
#include <ctime>
#include <set>
#include <string>
#include <iostream>
using namespace std;

//functions for score calculation and lowercase conversion
bool lowercase(const string& word);
int scoreCalculator(const set<string>& words);

int main() {
    srand(time(NULL));

    Boggle boggle;

    //outputing the game to make it interactive 
    cout << "\n===========Boggle Game============" << endl;
    cout << boggle << endl << endl; //output the board

    cout << "You have 60 seconds to find as many words as possible." << endl;
    cout << "Enter words in lowercase only." << endl;
    cout << "Type 'done' to finish early." << endl;
    cout << "Good luck and get typing! :)" << endl;
    cout << endl;

    // Solve board
    BoggleSolver solver("american-english");
    clock_t solveStart = clock();
    set<string> allAnswers = solver.solve(boggle);
    clock_t solveEnd = clock();

    time_t startTime = time(NULL);
    set<string> playerWords;
    string word;

    while (true) {
        time_t elapsed = time(NULL) - startTime;

        if (elapsed >= 60) {
            cout << "\nTime's up!" << endl;
            break;
        }

        //calculate the time remaining for each input
        cout << "Time remaining " << (60 - elapsed) << "s | Enter word: ";
        cin >> word; //allow the user to input

        if (word == "done") break;

        if (!lowercase(word)) {
            cout << "Must be lowercase!" << endl;
            continue;
        }

        if (playerWords.count(word)) {
            cout << "You already found this word!" << endl;
        }
        else if (allAnswers.count(word)) {
            cout << "Good!" << endl;
            playerWords.insert(word);
        }
        else {
            cout << "Invalid word from board!" << endl;
        }
    }

    cout << "\n==============Game Over!================" << endl;

    cout << "You found " << playerWords.size()
         << " out of " << allAnswers.size() << " possible words." << endl;

    cout << "Player Score: " << scoreCalculator(playerWords) << endl;
    cout << "Maximum Score: " << scoreCalculator(allAnswers) << endl;
    cout << "Time elapsed for solver: "
         << double(solveEnd - solveStart) / CLOCKS_PER_SEC << "s" << endl;

    cout << "\n******Words Found*****" << endl;
    for (const string& w : playerWords) cout << w << " ";

    cout << "\n\n*****Words Missed*****" << endl;
    int count = 0;
    for (const string& w : allAnswers) {
        if (!playerWords.count(w)) {
            cout << w << " ";
            if (++count % 10 == 0) cout << endl;
        }
    }
    cout << endl;

    return 0;
}

//calculate the score 
int scoreCalculator(const set<string>& words) {
    int score = 0;
    for (const string& w : words) {
        int len = w.length();
        if (len >= 8) score += 11;
        else if (len == 7) score += 5;
        else if (len == 6) score += 3;
        else if (len == 5) score += 2;
        else if (len >= 3) score += 1;
    }
    return score;
}

bool lowercase(const string& word) {
    for (char c : word) {
        if (c < 'a' || c > 'z') return false;
    }
    return true;
}
