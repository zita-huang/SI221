/****
Name: Zita Huang
Lab 05, part 1
****/
#include "TradStack.h"
#include <iostream>
#include <cctype>   //for isdigit, also searched this up
using namespace std;

char pnws(istream &in) {
    char c;
    for (c = in.peek(); c == ' ' || c == '\t' || c == '\n'; c = in.peek())
        in.get();
    return c;
}

int main() {
    Stack<double> s;
    cout << "Enter Postfix Expression: ";

    while (true) {
        char c = pnws(cin);

        if (isdigit(c)) {
            //read in number
            double num;
            cin >> num;
            s.push(num);
        }
        else if (c == '+') {
            cin.get(); //take in +
            double a = s.pop();
            double b = s.pop();
            s.push(b + a); //compute
        }
        else if (c == '-') {
            cin.get(); //take in -
            double a = s.pop();
            double b = s.pop();
            s.push(b - a); //compute 
        }
        else if (c == '*') {
            cin.get(); //take in *
            double a = s.pop();
            double b = s.pop();
            s.push(b * a); //compute
        }
        else if (c == '/') {
            cin.get(); //take in /
            double a = s.pop();
            double b = s.pop();
            s.push(b / a); //compute
        }
        else if (c == '=') {
            cin.get(); //take in =
            cout << "Expression Evaluates to: " << s.pop() << endl;
            break;
        }
    }

    return 0;
}

