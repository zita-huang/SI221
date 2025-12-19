/***********************************************************
 ** Class List - a templated list implementation with a nice
 ** ADT!  Actually it's pretty simple, but we'll transition
 ** to the STL soon!
 ***********************************************************/
#pragma once
#include <cstdlib>

template <class DataType>
class List {
  // forward declare Node which is a private nested class
  class Node;

public:

  /** CLASS FOR ITERATING OVER LISTS **/
  class Iterator {
  public:
    DataType& get() const; // returns the item pointed to by Iterator
    void next(); // advances Iterator to the next list item
    bool equal(const Iterator &A) const; // returns true if caller and
                                         // 'A' point to same object
    Iterator(Node *p = NULL); // creates an Iterator with curr set to 'p'
                              // (or NULL if no Node is passed)
  private:
    Node *curr;
  };//end class Iterator

/***********************************************************
 ** INTERFACE: PUBLIC MEMBERS OF CLASS LIST
 ***********************************************************/
  List();
  ~List();

  // add2front creates a new node with val, points it to the
  // first node of the list and points head to that new node
  void add2front(const DataType &val);

  // add2back creates a new node with val and points the last
  // node and tail to that new node
  void add2back(const DataType &val);

  Iterator begin() const; // returns an Iterator to the item
                          // pointed to by the head of the list

  Iterator end() const; // returns an Iterator to NULL which is
                        // what the tail of the list links to

/***********************************************************
 ** INTERFACE: PRIVATE MEMBERS OF CLASS LIST
 ***********************************************************/
private:
  //disable Copy Constructor and Assignment operator
  List(const List<DataType> &L) { }
  List<DataType>& operator=(const List<DataType> &L) { }

  class Node {
  public:
    DataType data;
    Node *next;
    Node(const DataType &val = DataType(), Node *p = NULL) {
      data = val;
      next = p;
    }
  };//end class Node

  Node *head, *tail;
};// end class List


/***********************************************************
 ** DEFINITIONS OF LIST'S MEMBER FUNCTIONS
 ***********************************************************/
template <class DataType>
List<DataType>::List() {
  head = tail = NULL;
}

template <class DataType>
List<DataType>::~List() {
  if (head != NULL) {
    for(Node *curr = head, *after; curr != NULL; curr = after) {
      after = curr->next;
      delete curr;
    }
  }
}

template <class DataType>
void List<DataType>::add2front(const DataType &val) {
  head = new Node(val, head);
  if (tail == NULL)
    tail = head;
}

template <class DataType>
void List<DataType>::add2back(const DataType &val) {
  if (head != NULL) {
    tail->next = new Node(val,NULL);
    tail = tail->next;
  }
  else {
    tail = new Node(val,NULL);
    head = tail;
  }
}

template <class DataType>
typename List<DataType>::Iterator List<DataType>::begin() const {
  return Iterator(head);
}

template <class DataType>
typename List<DataType>::Iterator List<DataType>::end() const {
  return Iterator();
}

/***********************************************************
 ** DEFINITIONS OF ITERATORS MEMBER FUNCTIONS
 ***********************************************************/
template <class DataType>
List<DataType>::Iterator::Iterator(Node *p): curr(p) { }

template <class DataType>
DataType& List<DataType>::Iterator::get() const {
  return curr->data;
}

template <class DataType>
void List<DataType>::Iterator::next() {
  curr = curr->next;
}

template <class DataType>
bool List<DataType>::Iterator::equal(const Iterator &A) const {
  return curr == A.curr;
}
