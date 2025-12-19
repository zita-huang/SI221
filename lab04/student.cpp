/*****
Name: Zita Huang
Lab 04, Part 2
*****/
#include "student.h"
using namespace std;

//constructor
//googled this could not get it to work the normal way :(
Student::Student(const string &nm) : studentName(nm) {}


string Student::name() const {
    return studentName;
}

//add grade
void Student::addNextGrd(double grade, const string &type) {
    if (type == "exam") {
        exam.addNextGrd(grade);
    }
    else if (type == "quiz") {
        quiz.addNextGrd(grade);
    }
    else if (type == "homework") {
        homework.addNextGrd(grade);
    }
}

//calculate average
double Student::ave(const string &type) const {
    const Grades *t = nullptr;

    if (type == "exam") {
        t = &exam;
    }
    else if (type == "quiz") {
        t = &quiz;
    }
    else if (type == "homework") {
        t = &homework;
    }

    if (t == nullptr || t->numGrd() == 0) {
        return 0.0;
    }

    double sum = 0.0;
    for (int i = 0; i < t->numGrd(); i++) {
        sum += t->getGrd(i);
    }

    return sum / t->numGrd();
}
