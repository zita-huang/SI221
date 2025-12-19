/***************************************************
* Defines a class Point for manipulating points in
* the plane.  The user is kept away from the
* implementation using the public/ private mechanism.
* The user can create points (and initialize them),
* read data from an input stream to set point coordinates
* and, query the coordinates of points.
***************************************************/
#ifndef _POINT_
#define _POINT_
#include <iostream>
using namespace std;

class Point{
private:
  double x, y, z;

public:
  // constructor sets to (a,b,c) or defaults to (0,0,0)
  Point(double  a = 0.0,  double  b = 0.0,  double c = 0.0);

  double get_x() const;      // return x-coordinate
  double get_y() const;      // return y-coordinate
  double get_z() const;      // return z-coordinate
  void readIn(istream &IN);    // read point from IN in
                             // ordered triple format:
                             // (a.b,c.d,e.f)
  void write0ut(ostream &OUT);
};

Point midpoint(const Point &P, const Point &Q);
double distance(const Point &P, const Point &Q);
#endif