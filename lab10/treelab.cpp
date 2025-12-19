#include <string>
#include "Tree.h"
using namespace std;

//------ PART 1 ------------------------------------------
void insertInt(Tree<int> &T, int x){
    // integer x should be placed in the tree in the proper position
    TreeNode<int> *root = T.getRoot();
    TreeNode<int> *curr = root;
    TreeNode<int> *parent = NULL;

    while(curr != NULL){
        parent = curr;
        if(x < curr->getData()){
            curr = curr->getLeft();
        }
        else if(x > curr->getData()){
            curr = curr->getRight();
        }
        else
            return;
    }

    TreeNode<int> *newNode = new TreeNode<int>(x);
    if(x < parent->getData()){
        parent->setLeft(newNode); //add children to the parent
    }
    else if(x > parent->getData()){
        parent->setRight(newNode); //ad children to the parent
    }
    
}


//------ PART 2 ------------------------------------------
int getMax(Tree<int> &T){
    // retrieves the maximum integer value stored in the tree
    if(T.size() == 0){
        return 0;
    }

    TreeNode<int> *curr = T.getRoot();

    while(curr->getRight() != NULL){
        curr = curr->getRight(); //go to the right most leaf
    }

    return curr->getData(); //return the right most leaf
}

int getMin(Tree<int> &T){
    // retrieves the minimum integer value stored in the tree
    if(T.size() == 0)
        return 0;

    TreeNode<int> *curr = T.getRoot();

    while(curr->getLeft() != NULL){
        curr = curr->getLeft(); //go to the left most leaf
    }
    return curr->getData(); //return the left most leaf
}

//------ DON'T TOUCH BELOW HERE --------------------------

int main(){
  // set root
  Tree<int> T;

    int k;
    while(cin >> k){
        if(k <= 0 )
            break;

        if(T.size() == 0){
            T.createRoot(k);
        } else {
            insertInt(T, k);
        }
    }

  // Comment out for Part 2
  prettyPrint(T.getRoot());
  cout << "Size of tree: " << T.size() << endl;
  cout << "Max Value: " << getMax(T) << endl;
  cout << "Min Value: " << getMin(T) << endl;
  cout << "Max Depth: " << T.maxDepth(T.getRoot()) << endl;
  return 0;
}
