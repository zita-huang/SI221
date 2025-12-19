#include "Date.h"
#include <iostream>
using namespace std;

// Takes a year y (e.g. 1998) and returns true
// if it's a leap year and false otherwise
bool leapyear(int y){
  return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

// Takes a year y and month m (e.g. 2002 and 12) and
// returns the number of days in month m given that
// it falls in year y.  (The year matters because of
// February and leap years!)
int daysinmonth(int y, int m){
  if (m == 9 || m == 4 || m == 6 || m == 11)
    return 30;
  else if (m != 2)
    return 31;
  else
    if (leapyear(y))
      return 29;
    else
      return 28;
}

//not use the private variables
Date::Date(int m, int d, int y){
    month = m;
    date = d;
    year = y;
}

//readIn function using the class Date
void Date::readIn(istream &IN){
    char c;
    IN >> month >> c >> date >> c >> year;
}

//caculations to determine whether or not the entered month, date , year is greater
bool Date::before(const Date &other) {
    if(year != other.year){
        return year < other.year;
    }
    if(month != other.month){
        return month < other.month;
    }
    return date < other.date;
}

//increment the year and/or date 
void Date::inc(){
    date++;
    if(date > daysinmonth(year,month)){
        date = 1;
        month++;
        if(month > 12){
            month = 1;
            year++;
        }
    }
}