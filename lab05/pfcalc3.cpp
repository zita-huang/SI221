/****
Name: Zita Huang
Lab 05, part 2
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
    cout << ": ";

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
            double value = s.pop();
            cout << value << endl;
            s.push(value); //push the value back to the top of the stack
            cout << ": "; //compute
        }
        else if(c == 'p'){
            cin.get(); //take in p
            cout << "#";
            Stack<double> printOut; //make a temporary stack
            while(!(s.isEmpty())){
                printOut.push(s.pop()); //push the values of s to printOut
            }
            Stack<double> reverse; //make another stack to write in reverse for output
            while(!printOut.isEmpty()){
                double value = printOut.pop(); //copy the value
                cout << value << " ";
                s.push(value);
                reverse.push(value); //push the values from reverse out 
            }
            cout << endl;
            cout << ": ";
        }
        else if(c == 'q'){
            cin.get(); //take in q
            break;
        }
    }

    return 0;
}