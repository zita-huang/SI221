/**************************************************
 * driver.cpp - The program defined here is a simple
 * program for tracking student grades for two students,
 * Joe and Amy.  The user has the following commands:
 *
 * NG <type> <student01's grade> <student02's grade>
 * AV <type>
 * TG
 * QT
 *
 * Valid <type>s are "exam", "quiz", & "homework"
 * NG - enters new <type> grades for student01 and student02
 * AV - prints out the average for the provided <type>
 * TG - prints the total grades for students, weighting exams 50%,
 * quizes 30%, and homeworks 20%.
 * QT - quits the program
 **************************************************/
#include "student.h"
#include <string>
#include <iostream>
using namespace std;

// FUCNTION PROTOTYPES
// Prints out the total grade for student S, weighing
// exams 50%, quizzes 30% and homeworks 20%
double totgrd(const Student &S);

// MAIN FUNCTION
int main() {
  Student S1("Joe"), S2("Amy");
  string command;

  while(cin >> command && command != "QT") {
    if (command == "NG") {
      string tp;
      double g1, g2;
      cin >> tp >> g1 >> g2;
      S1.addNextGrd(g1,tp);
      S2.addNextGrd(g2,tp);
    }
    else if (command == "AV") {
      string tp;
      cin >> tp;
      cout << S1.name() << "'s " << tp << " average is " << S1.ave(tp) << endl;
      cout << S2.name() << "'s " << tp << " average is " << S2.ave(tp) << endl;
    }
    else if (command == "TG") {
      cout << S1.name() << "'s total grade is " << totgrd(S1) << endl;
      cout << S2.name() << "'s total grade is " << totgrd(S2) << endl;
    }
    else
      cout << "Unknown command!" << endl;
  }

  return 0;
}

// FUNCTION DEFINITIONS
double totgrd(const Student &S){
  return 0.5*S.ave("exam") + 0.3*S.ave("quiz") + 0.2*S.ave("homework");
}