#include "bogglesolver.h"
#include <fstream>
#include <set>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

//open up the file
BoggleSolver::BoggleSolver(string filename){
    ifstream infile;
    infile.open(filename);
    string word;
    //read in all words of the dictionary
    while(infile >> word){
        if(word.length() >= 3){
            bool valid = true;
            for(int i = 0; i < word.length(); i++){
                //ensure that it will all be lowercase contents
                if(word[i] < 'a' || word[i] > 'z'){
                    valid = false;
                    break;
                }
            }
            if(valid){
                dictionary.insert(word);
            }
        }
    }
    infile.close();
}

bool BoggleSolver::hasPrefix(const string& prefix) {
    set<string>::iterator it = dictionary.lower_bound(prefix);

    if (it == dictionary.end())
        return false;

    // Compare the first prefix.length() characters
    return it->compare(0, prefix.length(), prefix) == 0;
}

//boggle solve function
set<string> BoggleSolver::solve(Boggle boggle){
    set<string> results;
    vector<vector<char>> letters(5, vector<char>(5));
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            int index = i * 5 + j;
            char c = boggle.dice[index].get();
            if(c >= 'A' && c <= 'Z'){
                c = c + 32; //convert the die face from uppercase to lowercase
            }
            letters[i][j] = c;
        }
    }

    //store all found words into the vector of strings 
    for(int row = 0; row < 5; row++){
        for(int col = 0; col < 5; col++){
            vector<vector<bool>> used(5, vector<bool>(5, false));
            set<string> found = findWords("", row, col, letters, used);
            results.insert(found.begin(), found.end()); //store em words
        }
    }
    return results;
}

//find all words within the board
set<string> BoggleSolver::findWords(string soFar, int row, int col,
                                    const vector<vector<char>>& letters,
                                    vector<vector<bool>>& used)
{
    set<string> results; //have a set of strings to store the results in

    if (row < 0 || row >= 5 || col < 0 || col >= 5) return results;
    if (used[row][col]) return results;
    string nextWord = soFar; //start new word from current die face
    char current = letters[row][col];
    nextWord += current;

    //handle QU
    if (current == 'q') {
        nextWord += 'u';
    }
    
    if (!hasPrefix(nextWord)) {
        return results;
    }

    if (nextWord.length() >= 3 && dictionary.count(nextWord)) {
        results.insert(nextWord);
    }

    used[row][col] = true;

    //recursion steps 
    static int dRow[] = {-1,-1,-1, 0,0, 1,1,1};
    static int dCol[] = {-1, 0, 1,-1,1,-1,0,1};

    for (int i = 0; i < 8; i++) {
        set<string> sub = findWords(nextWord, row + dRow[i], col + dCol[i],
                                    letters, used);
        results.insert(sub.begin(), sub.end());
    }

    used[row][col] = false;

    return results;
}
