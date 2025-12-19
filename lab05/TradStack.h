#include <stack>
using namespace std;
#ifndef _SI221STACK_
#define _SI221STACK_

/***************************************************
 * This is a nice definition of a class for the
 * traditional stack.
 ***************************************************/
template<class DataType>
class Stack {
public:

  Stack();
  ~Stack();
  bool isEmpty() const;
  void push(const DataType &newItem);
  DataType pop();

private:
  Stack(const Stack &S) { }
  Stack& operator=(const Stack &S) { }
  stack<DataType> *I;
};










/***************************************************
 ** DON'T LOOK BELOW THIS LINE! ********************
 ***************************************************/
template<class T>
Stack<T>::Stack() { I = new stack<T>; }

template<class T>
Stack<T>::~Stack() { delete I; }

template<class T>
bool Stack<T>::isEmpty() const { return I->empty(); }

template<class T>
void Stack<T>::push(const T &val) { I->push(val); }

template<class T>
T Stack<T>::pop() { T x = I->top(); I->pop(); return x; }

#endif
