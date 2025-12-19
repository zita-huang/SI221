#include <iostream>
#include <string>
#include "LabList.h"
using namespace std;

// printList(List,Iterator,ostream) is a helper function which uses
// member functions to traverse a list and print each item
void printList(const List<string> &L, ostream &OUT);

int main () {
  // add "this is just a test" to the list
  List<string> L;
  L.add2back("just");
  L.add2front("is");
  L.add2back("a");
  L.add2back("test");
  L.add2front("this");

  // PART 1
  // length should be 5
  cout << "Part 1 - Length: " << L.length() << endl;

  // PART 2
  // copy the list to another list
  List<string> L2;
  L.copyList(L2);
  //print the new list
  cout << "Part 2 - Copy:   ";
  printList(L2, cout);
  //secondary PART 2 verification
  //copying an empty list
  List<string> L2new1;
  List<string> L2new2;
  L2new1.copyList(L2new2);

  // PART 3
  // advance an iterator to the word "just"
  List<string>::Iterator itrChange = L.begin();
  itrChange.next();
  itrChange.next();
  // change statement to "this is really just a test"
  L.insertBefore("really",itrChange);
  // print the new list
  cout << "Part 3 - Insert: ";
  printList(L, cout);
  //secondary PART 3 verification
  //add items before the beginning of an empty list
  List<string> L3;
  List<string>::Iterator newItr = L3.begin();
  L3.insertBefore("", newItr);
  L3.insertBefore("", newItr);

  // PART 4
  // change statement to "this is really a test"
  L.remove(itrChange);
  // print the new list
  cout << "Part 4 - Remove: ";
  printList(L, cout);
  //secondary PART 4 verification
  //attempt to remove an item from an empty list
  List<string> L4;
  newItr = L4.begin();
  L4.remove(newItr);

  return 0;
}

void printList(const List<string> &L, ostream &OUT) {
  for(List<string>::Iterator I = L.begin(); !I.equal(L.end()); I.next())
  cout << I.get() << ' ';
  cout << endl;
}
