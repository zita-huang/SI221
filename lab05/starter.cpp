#include "TradStack.h"
#include <iostream>
using namespace std;

// pnws(in) eats up whitespace until finding a non-whitespace character,
// "peeks" at that character, and returns it without actually reading it.
// This allows another statement to "get" that character from the istream.
char pnws(istream &in) {
  char c;
  for(c = in.peek(); c == ' ' || c == '\t' || c == '\n'; c = in.peek())
    in.get();
  return c;
}


int main() {
  // prompt for postfix expression; initialize a stack of doubles


  // while there is more to read (use pnws here; also check for '=')


    // if the next input is an operator


      // read the next character


      // pop two numbers off the stack, minding proper order


      // determine proper operation; push result onto the stack


    // else read the next input and push it onto the stack


  // pop and print the answer (the last number on the stack)


  return 0;
}
