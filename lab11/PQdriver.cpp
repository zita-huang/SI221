/***************************************************************
 ** PQdriver.cpp - provides a driver file for testing the
 ** Priority Queue class.
 **
 ** This driver program is provided for testing, but is by no
 ** means complete. You should modify it as you see fit to test
 ** your implemented solution for correctness in both insertion
 ** and removal of elements.
 **
 ** Word to the wise: if you're not sure what your heap should
 ** look like, self-test exercises 5 and 6 in chapter 11, along
 ** with the answers to those questions found at the end of the
 ** chapter, would be very helpful in verifying that your heap
 ** works as intended.
 **************************************************************/
#include "PriQueue.h"
#include <string>
using namespace std;

int main(){
  // construct an empty Priority Queue
  PriorityQueue<int> intPQ;
  cout << "Empty before enqueues? " << intPQ.isEmpty() << endl;
  // fill the priority queue
  for(int i = 1; i <= 10; i++)
    intPQ.enqueue(i, i);
  // test basic functionality
  cout << "Highest priority: " << intPQ.getFront() << endl;
  cout << "Size: " << intPQ.size() << endl;
  cout << "Empty after enqueues? " << intPQ.isEmpty() << endl;
  // test print function and verify proper contents against book's answer
  cout << endl << "Heap after enqueues: " << endl;
  intPQ.printTree();
  // save dequeue'd values just in case I want to see them later
  int savedInts[3];
  for(int i = 0; i < 3; i++)
    savedInts[i] = intPQ.dequeue();
  // test print function and verify proper contents against book's answer
  cout << endl << "Heap after dequeues: " << endl;
  intPQ.printTree();


  // just for fun...
  cout << endl << "Just for fun..." << endl;
  PriorityQueue<string> stringPQ;
  string theAnts[10] = {"hurrah.", "hurrah,", "one", "by", "one",
                        "marching", "go", "ants", "the", "oh"};
  // enqueue "hurrah. hurrah, one by one marching go ants the oh"
  for(int i = 1; i <= 10; i++)
    stringPQ.enqueue(theAnts[i-1], i);
  // see what the heap looks like (which is nonsense, really)
  stringPQ.printTree();
  // dequeue in proper priority, which is reverse of the original input string
  cout << endl;
  for(int i = 0; i < 10; i++)
    cout << stringPQ.dequeue() << " ";
  cout << endl;

  return 0;
}
