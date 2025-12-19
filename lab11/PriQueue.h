/***************************************************************
 ** Class PriorityQueue - a templated queue class which uses a
 ** heap to store elements and supports normal queue operations.
 **
 ** Public member function descriptions:
 **   1) [constructor] - sets private data members as req'd
 **   2) enqueue - takes as arguments (a) data by reference
 **        and (b) int priority, inserts that element into the
 **        heap, and performs a heapify upward operation based
 **        on that element's priority
 **   3) dequeue - removes the root element and performs a
 **        heapify downward operation based on the new root
 **        element's priority
 **   4) getFront - returns the data of the root element
 **   5) size - returns the number of elements currently in the
 **        priority queue
 **   6) isEmpty - returns a boolean value based on the number
 **        of elements currently in the priority queue
 **   7) printTree - prints heap data in rotated tree format
 **
 ** Private data member descriptions:
 **   1) a nested class or struct "Element" (contains templated
 **        data and an integer priority)
 **   2) a static const int representing a maximum capacity of 100
 **   3) the heap (a static array of elements of size capacity)
 **   4) the number of elements currently in the priority queue
 **
 ** This class is adapted from the Priority Queue Class included
 ** in Data Structures and Other Objects Using C++, 4th Edition.
 **************************************************************/
#ifndef _SI221PRIORITYQUEUE_
#define _SI221PRIORITYQUEUE_
#include <cstdlib>
#include <iostream>

/*You must choose your BASE*/
const int BASE = 0;

template <class DataType>
class PriorityQueue{
public:
  PriorityQueue();
  void enqueue(const DataType& newData, int newPri);
  DataType dequeue();
  DataType getFront() const;
  int size() const;
  bool isEmpty() const;
  void printTree(int index = BASE, int depth = 0) const;

private:
  struct Element{
    DataType data;
    int priority;
  };

  static const int CAPACITY = 100;
  Element heap[CAPACITY];

  int numElements;

  void swap(int index1, int index2); // swaps heap[index1] and heap[index2]
  int findHighestChild(int index) const; // returns index of highest child
  bool isChildHigher(int index) const; // compares priority
  int getRightChild(int index) const; // returns index of right child
  int getLeftChild(int index) const; // returns index of left child

};

/***************************************************************
 ** DEFINITIONS OF PRIORITYQUEUE'S MEMBER FUNCTIONS
 **************************************************************/

/** Public Member Functions **/

template <class DataType>
PriorityQueue<DataType>::PriorityQueue() : numElements(0) {
}

template <class DataType>
void PriorityQueue<DataType>::enqueue(const DataType& newData, int newPri){
  // PART 1
  if (numElements >= CAPACITY)
    return;
  heap[numElements].data = newData;
  heap[numElements].priority = newPri;

  int curr = numElements;
  while(curr > BASE){
    int parent = (curr - 1) / 2;
    if(heap[curr].priority > heap[parent].priority){
      swap(curr, parent);
      curr = parent;
    }
    else{
      break;
    }
  }
  numElements++;
}

template <class DataType>
DataType PriorityQueue<DataType>::dequeue(){
  // PART 2
  DataType front = heap[0].data;

  numElements--;
  heap[0] = heap[numElements];

  int curr = 0;
  while(isChildHigher(curr)){
    int higherChild = findHighestChild(curr);
    swap(curr, higherChild);
    curr = higherChild;
  }

  return front;
}

template <class DataType>
DataType PriorityQueue<DataType>::getFront() const{
  // PART 3
  return heap[0].data;
}

template <class DataType>
int PriorityQueue<DataType>::size() const{
  // PART 3
  return numElements;
}

template <class DataType>
bool PriorityQueue<DataType>::isEmpty() const{
  // PART 3
  return (numElements == 0);
}

template <class DataType>
void PriorityQueue<DataType>::printTree(int index, int depth) const{
  if(!isEmpty() && index < numElements+BASE)  {
    printTree(getRightChild(index), depth+1);
    // print 4 spaces per level of depth in the tree
    for(int i = 0; i < depth; i++)
      std::cout << "    ";
    std::cout << heap[index].data << std::endl;
    printTree(getLeftChild(index), depth+1);
  }
}

/** Private Member Functions **/

template <class DataType>
void PriorityQueue<DataType>::swap(int index1, int index2){
  // swap the elements at index 1 and index 2
  Element temp = heap[index1];
  heap[index1] = heap[index2];
  heap[index2] = temp;
}

template <class DataType>
bool PriorityQueue<DataType>::isChildHigher(int index) const{
  // return true if either child priority is greater than the
  // priority of the element at the given index
  int leftChild = getLeftChild(index);
  int rightChild = getRightChild(index);

  if(leftChild < numElements && heap[leftChild].priority > heap[index].priority){
    return true;
  }

  if(leftChild < numElements && heap[rightChild].priority > heap[index].priority){
    return true;
  }

  return false;
}

template <class DataType>
int PriorityQueue<DataType>::findHighestChild(int index) const{
  // return the index value of the given node's highest child
  int leftChild = getLeftChild(index);
  int rightChild = getRightChild(index);

  if(rightChild >= numElements){
    return leftChild;
  }

  if(heap[leftChild].priority > heap[rightChild].priority){
    return leftChild;
  }
  else{
    return rightChild;
  }
}

template <class DataType>
int PriorityQueue<DataType>::getRightChild(int index) const{
  // return the index value of the given element's right child
  return 2 * index + 2;
}

template <class DataType>
int PriorityQueue<DataType>::getLeftChild(int index) const{
  // return the index value of the given element's left child
  return (2 * index + 1);
}

#endif
