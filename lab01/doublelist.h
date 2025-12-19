/*************************************************
 * This file provides class definitions and
 * function prototypes for basic linked lists
 * of doubles.
 *
 * Copyright Chris Brown, Jan 2, 2002. Anyone has
 * permission to use this code, but not to modify
 * it!
 *************************************************/
#ifndef _DOUBLELIST_
#define _DOUBLELIST_

/* List Node type.  A list is a pointer to a node */
class DoubleNode
{
 public:
  double data;
  DoubleNode* next;
};

/* add2front(val,L) adds val to the front of list L */
void add2front(double val, DoubleNode* &L);

/* deletelist(L) deletes the nodes of the list L */
void deletelist(DoubleNode *L);

#endif


