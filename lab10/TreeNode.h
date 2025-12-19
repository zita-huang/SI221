/***************************************************************
 ** Class TreeNode - a templated binary tree node class for
 ** representing binary trees.  A full tree composed of
 ** TreeNodes is represented by a pointer to the root TreeNode.
 ** This class is a modified version of binary_tree_node found
 ** in Data Structures and Other Objects Using C++, 4th Edition.
 **************************************************************/
#ifndef _SI221TREENODE_
#define _SI221TREENODE_
#include <cstdlib>
#include <iostream>

template <class DataType>
class TreeNode{
public:
  /** CONSTRUCTOR WITH DEFAULT ARGUMENTS **/
  TreeNode(const DataType &value = DataType(),
           TreeNode *left = NULL,
       TreeNode *right = NULL);

  /** GETTER AND SETTER FUNCTIONS **/
  DataType& getData(); // returns data by reference
  TreeNode*& getLeft(); // returns a pointer to left
  TreeNode*& getRight(); // returns a pointer to right
  void setData(const DataType& newData); // sets data to newData
  void setLeft(TreeNode* newLeft); // points leftChild to newLeft
  void setRight(TreeNode* newRight); // points rightChild to newRight

  /** OTHER FUNCTIONS **/
  bool isLeaf() const; // returns true if leftChild and rightChild are NULL

private:
  DataType data;
  TreeNode *leftChild, *rightChild;
};

/***************************************************************
 ** DEFINITIONS OF TREENODE'S MEMBER FUNCTIONS
 **************************************************************/

template <class DataType>
TreeNode<DataType>::TreeNode(const DataType &value, TreeNode *left, TreeNode *right){ data = value; leftChild = left; rightChild = right; }

template <class DataType>
DataType& TreeNode<DataType>::getData(){ return data; }

template <class DataType>
TreeNode<DataType>*& TreeNode<DataType>::getLeft(){ return leftChild; }

template <class DataType>
TreeNode<DataType>*& TreeNode<DataType>::getRight(){ return rightChild; }

template <class DataType>
void TreeNode<DataType>::setData(const DataType& newData){ data = newData; }

template <class DataType>
void TreeNode<DataType>::setLeft(TreeNode* newLeft){ leftChild = newLeft; }

template <class DataType>
void TreeNode<DataType>::setRight(TreeNode* newRight){ rightChild = newRight; }

template <class DataType>
bool TreeNode<DataType>::isLeaf() const{ return (leftChild == NULL) && (rightChild == NULL); }

/***************************************************************
 ** HELPER FUNCTIONS FOR THE TREENODE CLASS
 **************************************************************/

// clearTree takes a root pointer to a binary tree, deletes all
// nodes below it, and sets the root pointer to NULL
template <class DataType>
void clearTree(TreeNode<DataType>*& rootPtr){
  if(rootPtr != NULL){ 
    clearTree(rootPtr->getLeft());  // clear left subtree
    clearTree(rootPtr->getRight()); // clear right subtree
    delete rootPtr;   // return root to the heap
    rootPtr = NULL;
  }
}

// copyTree takes a root pointer to a binary tree, makes a copy
// of that tree, and returns a pointer to the root of this copy
template <class DataType>
TreeNode<DataType>* copyTree(TreeNode<DataType>*& rootPtr){
  TreeNode<DataType> *leftPtr, *rightPtr;
  if(rootPtr == NULL) return NULL;
  else{
    leftPtr = copyTree(rootPtr->getLeft());   // copy right
    rightPtr = copyTree(rootPtr->getRight()); // copy left
    return new TreeNode<DataType>(rootPtr->getData(),
                                  leftPtr, rightPtr);
  }
}

// size takes a pointer to a node in a binary tree and returns
// the size of its left and right subtrees plus itself
template <class DataType>
int size(TreeNode<DataType>* nodePtr){
  if(nodePtr == NULL) return 0;
  else return 1 + size(nodePtr->getLeft()) + size(nodePtr->getRight());
}

/***************************************************************
 ** TREE TRAVERSAL FUNCTIONS FOR THE TREENODE CLASS
 **************************************************************/

// printPreorder takes a pointer to a node in a binary tree and
// writes all descendants of that node to the given output
// stream using a pre-order traversal
template <class DataType>
void printPreorder(const TreeNode<DataType>* nodePtr){
  if(nodePtr != NULL){
    std::cout << nodePtr->getData() << std::endl;
    printPreorder(nodePtr->getLeft());
    printPreorder(nodePtr->getRight());
  }
}

// printInorder takes a pointer to a node in a binary tree and
// writes all descendants of that node to standard output using
// an in-order traversal
template <class DataType>
void printInorder(const TreeNode<DataType>* nodePtr){
  if(nodePtr != NULL){
    printPreorder(nodePtr->getLeft());
    std::cout << nodePtr->getData() << std::endl;
    printPreorder(nodePtr->getRight());
  }
}

// printPostorder takes a pointer to a node in a binary tree and
// writes all descendants of that node to standard output using
// an in-order traversal
template <class DataType>
void printPostorder(const TreeNode<DataType>* nodePtr){
  if(nodePtr != NULL){
    printPreorder(nodePtr->getLeft());
    printPreorder(nodePtr->getRight());
    std::cout << nodePtr->getData() << std::endl;
  }
}

// prettyPrint takes a pointer to a node in a binary tree
// writes all descendants of that node to standard output using
// a reversed in-order traversal for proper orientation
template <class DataType>
void prettyPrint(TreeNode<DataType>* nodePtr, int depth = 0){
  if(nodePtr != NULL){
    prettyPrint(nodePtr->getRight(), depth+1);
    // print 2 spaces per level of depth in the tree
    for(int i = 0; i < depth; i++)
      std::cout << "  ";
    std::cout << nodePtr->getData() << std::endl;
    prettyPrint(nodePtr->getLeft(), depth+1);
  }
}

#endif
