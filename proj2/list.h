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
    DataType& get() const; 
    void next(); 
    bool equal(const Iterator &A) const; 
    Iterator(); 
    
    // the two friend functions below allow List to access private
    friend void List<DataType>::insertBefore(DataType val, Iterator &I);
    friend void List<DataType>::remove(Iterator &I);
  private:
    Node *curr;
    Node* pred;
    Iterator(Node *p); 
  };

/***********************************************************
 ** INTERFACE: PUBLIC MEMBERS OF CLASS LIST
 ***********************************************************/
  List();
  ~List();
  
  // *** FIXED: Deep copy functions added to prevent double-free ***
  List(const List<DataType> &L);
  List<DataType>& operator=(const List<DataType> &L);

  void add2front(const DataType &val);
  void add2back(const DataType &val);

  Iterator begin() const; 
  Iterator end() const; 

  // PROTOTYPES FOR ALL THE FUNCTIONS YOU WILL DEFINE BELOW
  int length() const;                           
  void copyList(List<DataType> &L) const;       
  void insertBefore(DataType val, Iterator &I); 
  void remove(Iterator &I);                     


/***********************************************************
 ** INTERFACE: PRIVATE MEMBERS OF CLASS LIST
 ***********************************************************/
private:
  // The copy control members are now public methods defined below
  // We keep the Node definition here
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

// ** FIXED: DEEP COPY CONSTRUCTOR **
template <class DataType>
List<DataType>::List(const List<DataType> &L) {
    head = NULL; tail = NULL; // Initialize new list
    L.copyList(*this);       // Use your existing copyList function
}

// ** FIXED: COPY ASSIGNMENT OPERATOR **
template <class DataType>
List<DataType>& List<DataType>::operator=(const List<DataType> &L) {
    if (this != &L) {
        // 1. Clear old list (Destructor logic)
        if (head != NULL) {
            for(Node *curr = head, *after; curr != NULL; curr = after) {
                after = curr->next;
                delete curr;
            }
        }
        head = NULL; tail = NULL;

        // 2. Copy new list
        L.copyList(*this);
    }
    return *this;
}

template <class DataType>
List<DataType>::~List() {
  // Correct destructor logic (as you had it)
  for(Node *curr = head, *after; curr != NULL; curr = after) {
    after = curr->next;
    delete curr;
  }
  // No need to set head/tail to NULL since the object is being destroyed
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
List<DataType>::Iterator::Iterator(): curr(NULL), pred(NULL) { }

template <class DataType>
List<DataType>::Iterator::Iterator(Node *p): curr(p), pred(NULL) { }

template <class DataType>
DataType& List<DataType>::Iterator::get() const {
  return curr->data;
}

template <class DataType>
void List<DataType>::Iterator::next() {
  pred = curr; 
  curr = curr->next;
}

template <class DataType>
bool List<DataType>::Iterator::equal(const Iterator &A) const {
  return curr == A.curr;
}


/***********************************************************
 ** DEFINITIONS OF YOUR NEW LIST MEMBER FUNCTIONS
 ***********************************************************/

/**
Function: length()
Purpose: Returns the number of elements in the list.
**/
template <class DataType>
int List<DataType>::length() const {
  int count = 0;
  for(Iterator itr = begin(); !itr.equal(end()); itr.next()){
    count++;
  }
  return count;
}

template <class DataType>
void List<DataType>::copyList(List<DataType> &L) const {
  if(head == NULL){
    return;
  }
  for(Iterator itr = begin(); !itr.equal(end()); itr.next()){
    L.add2back(itr.get());
  }
}

/**
Function: insertBefore(DataType val, Iterator &I)
Purpose: Inserts a new node with 'val' before the node pointed to by 'I'.
**/
template <class DataType>
void List<DataType>::insertBefore(DataType val, Iterator &I) {
  Node* newNode = new Node(val);

  if(head == NULL){
    head = tail = newNode;
    I.curr = head;
    I.pred = NULL;
    return;
  }

  if(I.pred == NULL){ // Inserting before the head
    newNode->next = head;
    head = newNode;
    I.pred = head;
    return;
  }
  
  // Inserting in the middle or right before the end
  newNode->next = I.curr;
  I.pred->next = newNode;
  I.pred = newNode;
}

/**
Function: remove(Iterator &I)
Purpose: Removes the node pointed to by 'I' and advances the iterator.
**/
template <class DataType>
void List<DataType>::remove(Iterator &I) {
  // If the list is empty or iterator is at end (NULL), do nothing
  if(head == NULL || I.curr == NULL){
    return;
  }

  Node* temp = I.curr;

  if(I.pred == NULL){ // Removing the head node
    head = head->next;
    
    // Update iterator after removal
    I.curr = head;
    I.pred = NULL;

    if(head == NULL){
      tail = NULL; // List is now empty
    }
  }
  else { // Removing a middle or tail node
    I.pred->next = I.curr->next;
    
    // Check if the removed node was the tail
    if(temp == tail){
      tail = I.pred; // Update tail pointer
    }
    
    // Move to next iterator once removed
    I.curr = I.pred->next; 
  }

  delete temp;
}
// END NEW STUFF