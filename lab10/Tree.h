 /***************************************************************
 ** Class Tree - a templated binary tree class which uses the
 ** templated TreeNode class to store data.  A Tree will have
 ** a root pointer, which is self-explanatory, and a pointer to
 ** the current node which may be moved throughout the Tree.
 ** This class stems from documentation for a Binary Tree Class
 ** in Data Structures and Other Objects Using C++, 4th Edition.
 **************************************************************/
#ifndef _SI221TREE_
#define _SI221TREE_
#include "TreeNode.h" // more Tree functionality found here

template <class DataType>
class Tree{
public:
  /** CONSTRUCTORS AND DESTRUCTOR **/
  Tree();
  ~Tree();

  /** GETTER AND SETTER FUNCTIONS **/
  DataType getCurrent() const; // returns data of current node
  TreeNode<DataType>*& getRoot(); // returns a pointer to root
  void createRoot(const DataType &value); // sets root & current to new node
  void setCurrent(const DataType &value); // sets data of current node
  void addLeftChild(const DataType &value);  // adds a left child to current
  void addRightChild(const DataType &value); // adds a right child to current

  /** FUNCTIONS FOR MOVING CURRENT POINTER **/
  void gotoRoot(); // points current to root
  void gotoParent(); // points current to the parent of current
  void gotoLeftChild(); // points current to the left child of current
  void gotoRightChild(); // points current to the right child of current

  /** OTHER FUNCTIONS **/
  int size(); // returns the number of nodes in the Tree
  bool hasParent() const; // returns true if current has a parent
  bool hasLeftChild() const; // returns true if current has a left child
  bool hasRightChild() const; // returns true if current has a right child
  // findParent aids gotoParent by finding the parent of current
  TreeNode<DataType>*& findParent(TreeNode<DataType>*& curr) const;

  /** STUDENT IMPLMEMENTED FUNCTION **/
  int maxDepth(TreeNode<DataType>*& curr); // returns the depth maximum depth of the tree

private:
  Tree<DataType>& operator=(const Tree<DataType> &T);
  TreeNode<DataType> *root, *current;
  int numNodes;
};

/***************************************************************
 ** DEFINITIONS OF TREE'S MEMBER FUNCTIONS
 **************************************************************/

/** CONSTRUCTORS AND DESTRUCTOR **/
template <class DataType>
Tree<DataType>::Tree() { root = NULL; current = NULL; numNodes = 0; }

template <class DataType>
Tree<DataType>::~Tree() { clearTree(root); }

/** GETTER AND SETTER FUNCTIONS **/
template <class DataType>
DataType Tree<DataType>::getCurrent() const{ return current->getData(); }

template <class DataType>
TreeNode<DataType>*& Tree<DataType>::getRoot(){ return root; }

template <class DataType>
void Tree<DataType>::createRoot(const DataType &value){
  if(numNodes == 0){
    root = new TreeNode<DataType>(value);
    current = root;
    numNodes++;
  }
}

template <class DataType>
void Tree<DataType>::setCurrent(const DataType &value){ if(size() > 0) current->setData(value); }

template <class DataType>
void Tree<DataType>::addLeftChild(const DataType &value){
  if(numNodes > 0 && hasLeftChild() == false){
    current->setLeft(new TreeNode<DataType>(value));
    numNodes++;
  }
}

template <class DataType>
void Tree<DataType>::addRightChild(const DataType &value){
  if(numNodes > 0 && hasRightChild() == false){
    current->setRight(new TreeNode<DataType>(value));
    numNodes++;
  }
}

/** FUNCTIONS FOR MOVING CURRENT POINTER **/
template <class DataType>
void Tree<DataType>::gotoRoot() { current = root; }

template <class DataType>
void Tree<DataType>::gotoParent(){
  if(hasParent()) current = findParent(root);
}

template <class DataType>
void Tree<DataType>::gotoLeftChild(){
  if(hasLeftChild()) current = current->getLeft();
}

template <class DataType>
void Tree<DataType>::gotoRightChild(){
  if(hasRightChild()) current = current->getRight();
}

/** OTHER FUNCTIONS **/
template <class DataType>
int Tree<DataType>::size() { return::size(root); } //changed numNode to size(roots)

template <class DataType>
bool Tree<DataType>::hasParent() const { return current != root; }

template <class DataType>
bool Tree<DataType>::hasLeftChild() const{
  if(numNodes == 0) return false;
  else return current->getLeft() != NULL;
}

template <class DataType>
bool Tree<DataType>::hasRightChild() const{
  if(numNodes == 0) return false;
  else return current->getRight() != NULL;
}

template <class DataType>
TreeNode<DataType>*& Tree<DataType>::findParent(TreeNode<DataType>*& curr) const{
  if(curr == NULL) { return curr; } // base case, parent not found
  else if(curr->getLeft() == current || curr->getRight() == current){ return curr; } // we found the parent!
  else{ // recurse with subtrees rooted at leftChild and rightChild
    TreeNode<DataType> *temp = findParent(curr->getLeft());
    if(temp == NULL) return findParent(curr->getRight());
    else return temp; // this is the parent we found earlier
  }
}

//------ PART 3 ------------------------------------------

/* This function should return the maximum depth of the tree from the given node.
 * Remember: the root level starts at 0 (not 1)!s
 */
template <class DataType>
int Tree<DataType>::maxDepth(TreeNode<DataType>*& curr){
    // COMPLETE THIS FUNCTION
    if(curr == NULL)
      return -1;

    int left = maxDepth(curr->getLeft()); //go to the left most node 
    int right = maxDepth(curr->getRight()); //go to the right most node

    if(left > right) //compare which node is farther 
      return left + 1; //calculate the levels
    else
      return right + 1; //calculate the levels
}


#endif
