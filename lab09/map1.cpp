#include <iostream>
#include <map>
#include <utility>
using namespace std;

int main(){
    map<string,double> M;
    pair<string,double> PG("gold",14.21);
    pair<string,double> PS("silver",8.00);
    pair<string,double> PB("bronze",2.25);

    M.insert(PG);
    M.insert(PS);
    M.insert(PB);

    // Print out per ounce of material from user input
    string input;
    cin >> input;
    map<string,double>::iterator itr = M.find(input);
    if (itr != M.end())
        cout << (*itr).second << endl;
    else
        cout << "No match found!" << endl;
}