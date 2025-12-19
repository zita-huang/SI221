/* Implements functions from doublelist.h  
 *
 * Copyright Chris Brown, Jan 2, 2002. Anyone has
 * permission to use this code, but not to modify
 * it!
 */
#include "doublelist.h"

void add2front(double val, DoubleNode* &L)
{
  DoubleNode *T = new DoubleNode;
  T->data = val;
  T->next = L;
  L = T;
}

void deletelist(DoubleNode *L)
{
  while(L != 0)
  {
    DoubleNode *T = L;
    L = L->next;
    delete T;
  }
}
