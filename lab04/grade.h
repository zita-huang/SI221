/****************************************************
 * grade.h --- Interface for the Grades module.
 * Class Grades allows you to store grades and retrieve them by "index".
 * The first grade you store has index 0, the second grade you store has index 1, etc.
 ****************************************************/

/** DECLARATION of class Node **/
class Node;

/** DEFINITION of class Grades **/
class Grades{
private:
  // Disable pass-by-value and assignment!
  Grades(const Grades&) { }
  Grades& operator=(const Grades &G);

public:
  Grades() {
    head = tail = 0;
    n = 0;
  }
  ~Grades();

  // adds a grade (positive grades only)
  void addNextGrd(double score);

  // retrieves grade from index - if a
  // negative grade is returned, then
  // there was no grade with that index!
  double getGrd(int index) const;

  // returns number of grades
  int numGrd() const {
    return n;
  }

private:
  Node *head, *tail;
  int n;
};