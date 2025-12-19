/****
Name: Zita Huang
Lab 4, student.h
****/
#include "grade.h"
#include <string>

class Student {
private:
    std::string studentName;
    Grades exam;      
    Grades quiz;
    Grades homework;

public:
    // constructor
    Student(const std::string &name);
    std::string name() const;

    // add grade
    void addNextGrd(double grade, const std::string &type);

    // calculate average
    double ave(const std::string &type) const;
};

