#include <queue>
using namespace std;
#ifndef _SI221QUEUE_
#define _SI221QUEUE_

/***************************************************
 * This is a nice definition of a class queue that
 * matches the traditional abstract data type.
 ***************************************************/
template<class DataType>
class Queue {
public:

  Queue();
  ~Queue();
  bool isEmpty() const;
  void enqueue(const DataType &val);
  DataType dequeue();
  DataType peek() const;

private:
  Queue(const Queue &Q) { }
  Queue& operator=(const Queue &Q) { }
  queue<DataType> *I;
};










/***************************************************
 ** DON'T LOOK BELOW THIS LINE! ********************
 ***************************************************/
template<class T>
Queue<T>::Queue() { I = new queue<T>; }

template<class T>
Queue<T>::~Queue() { delete I; }

template<class T>
bool Queue<T>::isEmpty() const { return I->empty(); }

template<class T>
void Queue<T>::enqueue(const T &val) { I->push(val); }

template<class T>
T Queue<T>::dequeue() { T val = I->front(); I->pop(); return val; }

template<class T>
T Queue<T>::peek() const { T val = I->front(); return val; }
#endif
