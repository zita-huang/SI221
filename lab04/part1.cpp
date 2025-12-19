/******
Name: Zita Huang
Lab 04 Part 1
******/
#include <iostream>
#include <string>
#include "grade.h"
using namespace std;

int main(){
    Grades student1, student2;
    string cmd;
    while(cin >> cmd){
        //Read in the inputed grades
        if(cmd == "NG"){
            double studentGrade1, studentGrade2;
            cin >> studentGrade1 >> studentGrade2; //read in scores
            student1.addNextGrd(studentGrade1);
            student2.addNextGrd(studentGrade2);
        }
        //obtain the average of both students
        else if(cmd == "AV"){
            int n = student1.numGrd(); //read in all the grades
            double sum1 = 0, sum2 = 0;
            double average1, average2;
            for(int i = 0; i < n; i++){
                sum1 += student1.getGrd(i); //add in all the grades
                sum2 += student2.getGrd(i);
            }
            //compute the average
            average1 = sum1/n;
            average2 = sum2/n;

            cout << "Student1's average is " << average1 << endl;
            cout << "Student2's average is " << average2 << endl;
        }
        //get the grade for a certain assignment number
        else if(cmd == "GD"){
            int index;
            cin >> index; //read in the index
            double std1Index = student1.getGrd(index); //get the grade for the index
            double std2Index = student2.getGrd(index);
            //index notice if no grade is persent in the assignment number/index
            if(std1Index < 0 || std2Index < 0){
                cout << "No grade for assignment " << index << endl;
            }
            else{
                cout << "Student1 got a " << std1Index << endl;
                cout << "Student2 got a " << std2Index << endl;
            }
        }
        else if(cmd == "QT"){
            break; //break out the loop
        }

    }
    return 0;
}
