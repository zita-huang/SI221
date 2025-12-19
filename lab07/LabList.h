/******************************************************************************
File: LabList.h
Name: Zita Huang 
Course/Section: SI221
Lab: 07 <name of the assignment>
Date: 10/09/2025
Description: Class List - a templated list implementation
Resources used: List all resources used except the course website.  If none,
state so.
Help received: List all help received, include the name of the individual and
topic.  If none, state so.
Help given: List all help given, include the name of the individual and
topic.  If none, state so.
******************************************************************************/

#pragma once
#include <cstdlib>

template <class DataType>
class List {
  // forward declare Node which is a private nested class
  class Node;

public:

  /** CLASS FOR ITERATING OVER LISTS **/
  class Iterator {
    friend class List;
  public:
    DataType& get() const; // returns the item pointed to by Iterator
    void next(); // advances Iterator to the next list item
    bool equal(const Iterator &A) const; // returns true if caller and
                                         // 'A' point to same object
    Iterator(); // creates an Iterator with curr set to NULL
    
    // the two friend functions below allow List to access private
    friend void List<DataType>::insertBefore(DataType val, Iterator &I);
    friend void List<DataType>::remove(Iterator &I);
  private:
    Node *curr;
    Node* pred;
    Iterator(Node *p); // creates an Iterator with curr set to 'p'

  };

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


  // PROTOTYPES FOR ALL THE FUNCTIONS YOU WILL DEFINE BELOW
  int length() const;                           /** PART 1 **/
  void copyList(List<DataType> &L) const;       /** PART 2 **/
  void insertBefore(DataType val, Iterator &I); /** PART 3 **/
  void remove(Iterator &I);                     /** PART 4 **/


/***********************************************************
 ** INTERFACE: PRIVATE MEMBERS OF CLASS LIST
 ***********************************************************/
private:
  //disable copy construtor and assignment operator
  List(const List<DataType> &L) { }
  List<DataType>& operator=(const List<DataType> &L) { }

  class Node {
  public:
    DataType data;
    Node *next;
    Node(const DataType &val = DataType(), Node *p = NULL) {
      data = val; next = p;
    }
  };//end class Node

  Node *head, *tail;
};


/***********************************************************
 ** DEFINITIONS OF LIST'S MEMBER FUNCTIONS
 ***********************************************************/
template <class DataType>
List<DataType>::List() {
  head = NULL; tail = NULL;
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
  head = new Node(val,head);
  if (tail == NULL)
    tail = head;
}

template <class DataType>
void List<DataType>::add2back(const DataType &val){
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
//implement in pred
List<DataType>::Iterator::Iterator(): curr(NULL), pred(NULL) { }

template <class DataType>
//implement in pred
List<DataType>::Iterator::Iterator(Node *p): curr(p), pred(NULL) { }

template <class DataType>
DataType& List<DataType>::Iterator::get() const {
  return curr->data;
}

template <class DataType>
void List<DataType>::Iterator::next() {
  pred = curr; //added in to implement pred
  curr = curr->next;
}

template <class DataType>
bool List<DataType>::Iterator::equal(const Iterator &A) const {
  return curr == A.curr;
}


/***********************************************************
 ** DEFINITIONS OF YOUR NEW LIST MEMBER FUNCTIONS
 ***********************************************************/

// NEW STUFF BELOW
/**
Function: length()
Purpose:  ????? -- fill me in!
**/
template <class DataType>
int List<DataType>::length() const {
  // PART 1 - fill me in!
  int count = 0;

  //return a count of 0 if list is empty
  if(head == NULL){
    return 0;
  }

  //increase the count for every itr gone through
  for(Iterator itr = begin(); !itr.equal(end()); itr.next()){
    count++;
  }
  return count;
}

/**
Function: copyList(List<DataType> &L) const
Purpose:  ????? -- fill me in!
**/
template <class DataType>
void List<DataType>::copyList(List<DataType> &L) const {
  // PART 2 - fill me in!
  //copy nothing if empty
  if(head == NULL){
    return;
  }

  //copy the list once elements are added
  for(Iterator itr = begin(); !itr.equal(end()); itr.next()){
    L.add2back(itr.get());
  }
}

/**
Function: insertBefore(DataType val, Iterator &I)
Purpose:  ????? -- fill me in!
**/
template <class DataType>
void List<DataType>::insertBefore(DataType val, Iterator &I) {
  // PART 3 - fill me in!
  Node* newNode = new Node(val);

  //empty the list
  if(head == NULL){
    head = tail = newNode;
    I.curr = head;
    I.pred = NULL;
    return;
  }

  //insert before the first node
  if(I.pred == NULL){
    newNode->next = head;
    head = newNode;
    I.pred = head;
    return;
  }
  //insert in the middle or right before the end of the list
  newNode->next = I.curr;
  I.pred->next = newNode;
  I.pred = newNode;
}

/**
Function: remove(Iterator &I)
Purpose:  ????? -- fill me in!
**/
template <class DataType>
void List<DataType>::remove(Iterator &I) {
  // PART 4 - fill me in!
  //empty list
  if(head == NULL || I.curr == NULL){
    return;
  }

  //remove first node
  if(I.pred == NULL){
    Node* temp = head;
    head = head->next;
    delete temp;

    //update both I.curr and I.pred
    I.curr = head;
    I.pred = NULL;

    //make sure it is empty
    if(head == NULL){
      tail = NULL; //set tail to empty
    }
    return;
  }

  //remvoing the middle or last node
  Node* temp = I.curr;
  I.pred->next = I.curr->next;

  //removing tail pointer
  if(I.curr == NULL){
    tail = I.pred; //update pointer
  }

  //move to next iterator once removed
  I.curr = I.pred->next;

  delete temp;
}
// END NEW STUFF
