#ifndef _DATE_
#define _DATE_
#include <iostream>
using namespace std;

class Date{
    private:
    int date, month, year;

    public:
    Date(int date = 1, int month = 1, int year = 1900); //initialize them all
    
    int get_date() const {
        return date; //return date
    }
    int get_month() const {
        return month; //return month
    }
    int get_year() const {
        return year; //return year
    }

    bool before(const Date &other); //comparison for the birthdays
    void inc(); //increment function
    void readIn(istream &IN); //read in the entered birthday
};



#endif