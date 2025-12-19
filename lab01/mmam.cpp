/************************************************
 * This program reads numbers from standard input
 * (i.e. through cin), computes min, max, and
 * average of the numbers, and prints these
 * values.
 ************************************************/
#include <iostream>
#include <string>
#include "doublelist.h"
#include "doublesort.h"
using namespace std;

//count the number of nodes
int countNode(DoubleNode* head){
  int count = 0;
  DoubleNode* current = head;
  while(current != NULL){
    count++;
    current = current->next;
  }
  return count;
}

//using the number of nodes counted, make it into a static array
void makearray(DoubleNode* head, double A[], int n){
  DoubleNode* current = head;
  int i = 0;
  while(current != NULL && i < n){
    A[i++] = current->data;
    current = current->next;
  }
}

int main(int argc, char* argv[]) {
  //String S that was taught in the lab
  bool Max, Min, Med, Avg;
  Max = Min = Med = Avg = false;
  if(argc == 1){
    Max = Min = Avg = Med = true;
  }
  for(int i = 0; i < argc; i++){
    string s = argv[i];
    if(s == "-max")
      Max = true;
    else if(s == "-min")
      Min = true;
    else if(s == "-average")
      Avg = true;
    else if(s == "-median")
      Med = true;
  }

  // Read 1st number & initialize values
  double next, min, max, sum;
  cin >> next;
  min = max = sum = next;
  int count = 1;

  DoubleNode* head = new DoubleNode{next, NULL};
  DoubleNode* P = head;

  // Read subsequent numbers and update min, max, sum and count
  while(cin >> next) {
    sum += next;
    count ++;
    if (next < min)
      min = next;
    if (next > max)
      max = next;
    DoubleNode* L = new DoubleNode{next, NULL};
    P->next = L;
    P = L;
  }

  //load the static array with the data
  int n = countNode(head);
  double A[n];
  makearray(head, A, n);
  doublesort(A, n);

  //calculate the median
  double median;
  if(n % 2 == 1){
    median = A[n/2];
  }
  else{
    median = (A[n/2 - 1] + A[n/2]) / 2.0;
  }

  // Print results
  if (Min){
    cout << "min = " << min << endl;
  }
  if(Max){
    cout << "max = " << max << endl;
  }
  if(Avg){
    cout << "avg = " << sum/count << endl;
  }
  if(Med){
    cout << "med = " << median << endl;
  }

  deletelist(head);

  return 0;
}

