#include "Point.h"
#include <iostream>
#include <cmath>
using namespace std;

//not use the private variables
Point::Point(double a, double b, double c){
  x = a;
  y = b;
  z = c;
}

//return x
double Point::get_x() const {
  return x;
}

//return y
double Point::get_y() const {
  return y;
}

//return z
double Point::get_z() const {
  return z;
}

//readIn function using the class Point
void Point::readIn(istream &IN){
  char c;
  IN >> c >> x >> c >> y >> c >> z >> c;
}

//write0ut function using the class Point
void Point::write0ut(ostream &OUT){
  char c;
  OUT << "(" << x << "," << y << "," << z << ")";
}

//determine the midpoint using the get function type
Point midpoint(const Point &P, const Point &Q){
  return Point((P.get_x() + Q.get_x())/2,
         (P.get_y() + Q.get_y())/2,
         (P.get_z() + Q.get_z())/2);
}

//determine the distance using math
double distance(const Point &P, const Point &Q){
  double dist_x = P.get_x() - Q.get_x();
  double dist_y = P.get_y() - Q.get_y();
  double dist_z = P.get_z() - Q.get_z();

  return sqrt((dist_x * dist_x) + (dist_y * dist_y) + (dist_z * dist_z));
}