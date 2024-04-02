#ifndef BST_H
#define BST_H

#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/*
 * Binary Search Tree Class
 */

// Binary Tree Node
template <typename T> struct tNode {
public:
  T item;                 // data containing item type T
  tNode<T> *left, *right; // left & right ptrs

  // line 128 change depending on

  // Default Constructor
  tNode() {}

  // initializing data members with empty left & right nodes
  tNode(const T &nodeItem, tNode<T> *lft = NULL, tNode<T> *rght = NULL)
      : left(lft), right(rght), item(nodeItem) {}


  // overloaded ostream operator for tNode

  // friend std::ostream &operator<<(std::ostream &os, const tNode<T> &rhs) {
  //    //os << rhs.item;
  //   os << "he";
  //   return os; }
};

// BST Class
template <typename T> class BST {
private:
  // root of tree
  tNode<T> *root;

  // Helper Functions

  // Recursive BST Insert Function
  tNode<T> *InsertRecursive(const T &insert_item, tNode<T> *ptr) {
    // create a new node if ptr of BST is NULL
    if (ptr == nullptr) {
      ptr = new tNode<T>(insert_item);
      
      return ptr;
    }
    // left tree
    else if (ptr->item > insert_item) {
      ptr->left = InsertRecursive(insert_item, ptr->left);
    }
    // right tree
    else if (ptr->item < insert_item) {
      ptr->right = InsertRecursive(insert_item, ptr->right);
    }
    return ptr;
  }

  // Recursive Node Traversals for Key Value Types
  tNode<T> *InsertRecursiveKV(const T &insert_item, tNode<T> *ptr) {
      // create a new node if ptr of BST is NULL
      if (ptr == NULL) {
        ptr = new tNode<T>(insert_item);
        return ptr;
      }

      // Duplicate Item is Updated
      if ( *(ptr->item) == *insert_item ){
          (*(ptr->item)).valueVal = (*insert_item).valueVal;
        return ptr;
      }

      // left tree
      else if ( *(ptr->item) > *insert_item) {
        ptr->left = InsertRecursive(insert_item, ptr->left);
      }
      // right tree
      else if ( *(ptr->item) < *insert_item) {
        ptr->right = InsertRecursive(insert_item, ptr->right);
      }


      return ptr;
    }  

  // Inorder Traversal Helper Function
  void const InorderTraversal(const tNode<T> *ptr) {
    if (ptr == nullptr)
      return;
    InorderTraversal(ptr->left);
    std::cout << (ptr->item) << " ";
    //Fix? for MAP *(ptr->item)
    InorderTraversal(ptr->right);
  }

  // recursive BST search
  tNode<T> *searchP(const T &find_item, tNode<T> *ptr) {
    if (ptr != NULL) {

      if ( *(ptr->item) == *find_item) {
        return ptr;
      }
      // find_item is less than current
      else if ( *(ptr->item) > *find_item) {
        return searchP(find_item, ptr->left);
      }
      // find_item is greater than current
      else if ( *(ptr->item) < *find_item) {
        return searchP(find_item, ptr->right);
      }
    }
    return NULL;
  }

  //Inorder Traversal Helper Function 
  //with overloaded key value pairs ostream operator  
  void const printInOrderr( const tNode<T> *ptr){

    if( ptr == nullptr ) 
      return;

    printInOrderr(ptr->left);
    std::cout<<  (*(ptr->item) ) <<" ";
    printInOrderr(ptr->right);
  }

  // traversal insert for overloaded assignment operator
  void TraverseInsert(tNode<T> *rt) {

    // inserting new node
    this->insert(rt->item);

    if (rt->left != NULL) {
      TraverseInsert(rt->left);
    }
    if (rt->right != NULL) {
      TraverseInsert(rt->right);
    }
  }

  // Recursive ClearBST helper function
  void ClearBST(tNode<T> *rt) {
    if (rt == nullptr)
      return;
    ClearBST(rt->left);
    ClearBST(rt->right);
    delete rt;
    rt = nullptr;
  }

  // Print Tree using Queue implementation helper function
  void DisplayTree(tNode<T> *rt, const string &delim = " ") {
    if (rt == nullptr)
      return;

    // initializing Queue
    queue<tNode<T> *> qu;

    // pointer
    tNode<T> *ptr;

    // pushing root
    qu.push(rt);

    while (!qu.empty()) {

      // set ptr to front of queue & pop
      ptr = qu.front();
      qu.pop();

      // printing out ptr
      std::cout << ptr->item << delim;

      if (ptr->left != NULL) {
        qu.push(ptr->left);
      }
      if (ptr->right != NULL) {
        qu.push(ptr->right);
      }
    }
  }

  // InfixTraversal for expression tree
  void const InfixTraversal(const tNode<T> *ptr) {
    // check for nullptr
    if (ptr == nullptr)
      return;
    if (isOperator(ptr->item)) {
      std::cout << "(";
    }
    InfixTraversal(ptr->left);
    std::cout << ptr->item;
    InfixTraversal(ptr->right);

    if (isOperator(ptr->item)) {
      std::cout << ")";
    }
  }

  // PreOrderTraversal
  void const PreOrderTraversal(const tNode<T> *ptr) {
    // visit root
    if (ptr == NULL)
      return;
    std::cout << ptr->item << " ";
    // visits left
    PreOrderTraversal(ptr->left);
    // visits right
    PreOrderTraversal(ptr->right);
  }

  // Recursive Solver
  double InorderSolverTraversal(const tNode<char> *ptr) {
    if (ptr == nullptr) {
      return 0;
    }

    // Check if node is a leaf
    // leaf is an operand
    /*
      Side Note: after performing operations from the tree
      ascii values were present

    */

    // if node is a leaf, return its value
    if (isLeaf(ptr)) {
      return ptr->item - '0';
    }

    // traversing left & right sub trees
    double left_val = InorderSolverTraversal(ptr->left);
    double right_val = InorderSolverTraversal(ptr->right);

    // Performs operation from root based on values
    return PerformOperation(ptr->item, left_val, right_val);
  }

  // Recursive BST Search Function
  tNode<T> *Search(const T &find_item, tNode<T> *ptr) {
    if (ptr != NULL) {

      if ( ptr->item == find_item) {
        return ptr;
      }
      // find_item is less than current
      else if (ptr->item > find_item) {
        return Search(find_item, ptr->left);
      }
      // find_item is greater than current
      else if (ptr->item < find_item) {
        return Search(find_item, ptr->right);
      }
    }
    return NULL;
  }
  
  
  // Recursive BST Search For Key Value Pairs 
  tNode<T> *SearchKV(const T &find_item, tNode<T> *ptr) {
    if (ptr != NULL) {

      if (*( ptr->item) == *find_item) {
        return ptr;
      }
      // find_item is less than current
      else if ( *(ptr->item) > *find_item) {
        return SearchKV(find_item, ptr->left);
      }
      // find_item is greater than current
      else if ( *(ptr->item) < *find_item) {
        return SearchKV(find_item, ptr->right);
      }
    }
    return NULL;
  }

public:
  // BST Default Constructor
  BST() : root(NULL) {}

  // BST Constructor
  BST(const T &input_item) : root(new tNode<T>(input_item)) {}

  // BST Constructor for two tNode<T> pointers
  BST(const T &input_item, tNode<T> *lft, tNode<T> *rht) {
    root = new tNode<T>(input_item, lft, rht);
  }

  // BST Constructor for Arithmetic Expression Stack Implementation Type One:)
  BST(const std::string &input_item, int one) {
    // create stack of tNode pointers
    std::stack<tNode<char> *> str;

    // traverse expression
    for (int i = 0; i < input_item.length(); i++) {

      // check if i is not an operator
      if (!isOperator(input_item[i])) {

        // push a new node containg sinlge operand element
        str.push(new tNode<char>(input_item[i]));
      }
      // check if i is operand
      else {
        // create two tnode pointers
        tNode<char> *treeLeft, *treeRight;

        // first pointer becomes top element containing digit
        treeRight = (str.top());
        str.pop();

        // second pointer becomes second element containing digit
        treeLeft = (str.top());
        str.pop();

        // new node root is created with root->element being operator
        // root left child equals treeOne
        // root right child equals treeTwo
        root = new tNode<char>(input_item[i], treeLeft, treeRight);
        // root  = new BST<char>(input_item[i]);

        // root -> left = treeOne;
        // root-> right = treeTwo;

        // root is pushed onto stack
        str.push(root);
      }
    }
  }

  // BST Constructor InOrder Arithmetic Expression Stack Implementation Type Two
  BST(const std::string &input_item, double two) {
    // stack for nodes
    std::stack<tNode<char> *> sNodes;

    // stack for root nodes
    std::stack<tNode<char> *> opNodes;

    // traverse string
    for (int i = 0; i < input_item.length(); i++) {

      // if( !isOperator(input_item[i]) && opNodes.size() < 1 ){
      if (!isOperator(input_item[i])) {

        sNodes.push(new tNode<char>(input_item[i]));
      }

      // if not operator
      if (!isOperator(input_item[i]) && !opNodes.empty()) {
        tNode<char> *treeLeft, *treeRight;

        treeRight = sNodes.top();
        sNodes.pop();
        treeLeft = sNodes.top();
        sNodes.pop();

        root->right = treeRight;
        root->left = treeLeft;

        sNodes.push(root);
      }
      // if it is operator
      else if (isOperator(input_item[i])) {
        root = new tNode<char>(input_item[i]);
        opNodes.push(root);
      }
    }
  }

  // Search Function for Key Value Pairs
  tNode<T>* searchP(const T& find_item)  {
        //return searchP(root, find_item);
        return SearchKV(find_item, root);
    }

  // check if char is an operator
  bool isOperator(const char &input_item) {
    return input_item == '+' || input_item == '-' || input_item == '*' ||
           input_item == '/' || input_item == '^';
  }

  // return root
  const tNode<T> *GetRoot() { return root; }

  // testing return right item
  void printData() { std::cout << root->right->item << " "; }

  // public Search Function
  void search(const T &input_item) {
    tNode<T> *ptr = Search(input_item, root);
    if (ptr == nullptr) {
      std::cout << "Input: " << (input_item) << " not found" << endl;
    } else {
      std::cout << "Input was found!" << input_item << endl;
    }
  }

  // finding Key Value Pairs 
  void printFind(const T &input_item) {
    tNode<T> *ptr = SearchKV(input_item, root);
    if (ptr == nullptr) {
      std::cout << "Input: " << *(input_item) << " not found" << endl;
    } else {
      std::cout << "Input was found!" << *input_item << endl;
    }
  }
  
  // finding Key Value Pairs 
  bool printValueFind(const T &input_item) {
    tNode<T> *ptr = SearchKV(input_item, root);
    if (ptr == nullptr) {
      std::cout << "Input: " << *(input_item) << " not found" << endl;
      return false;
    } else {
      std::cout << "Input was found!" << *input_item << endl;
      return true;
    }
  }

  // Insert Function
  void insert(const T &item) { root = InsertRecursive(item, root); }
  /*
    1. isTree Empty function
    2. insert Node into tree
    3. search function returning tNode pointer
  */

  void insertKV(const T &item) { root = InsertRecursiveKV(item, root); }

  // PreOrder Traversal Member Function
  void preOrder() { PreOrderTraversal(root); }

  // Inorder Traversal Member Function
  void inOrder() { InorderTraversal(root); }


  void printInOrder() { printInOrderr(root); }

  // Inorder Solve Member Function
  void InorderSolve() {
    double sum = InorderSolverTraversal(root);
    std::cout << "Binary Tree Expression equals: " << sum << endl;
  }

  // Performs operation based on char
  double PerformOperation(char ch, double left, double right) {
    if (ch == '+') {
      return left + right;
    }
    if (ch == '-') {
      return left - right;
    }
    if (ch == '*') {
      return left * right;
    }
    if (ch == '/') {
      return left / right;
    }
    if (ch == '^') {
      return pow(left, right);
    }
    return 0;
  }

  // Check if node is leaf
  bool isLeaf(const tNode<T> *ptr) {
    return ptr->left == nullptr && ptr->right == nullptr;
  }

  // Clear Function
  void Clear() { ClearBST(root); }

  // Overloaded Assignment operator
  BST<T> &operator=(const BST<T> rhs) {
    if (this != &rhs) {
      this->Clear();
      tNode<T> *start = rhs.root;
      TraverseInsert(start);
    }
    return *this;
  }

  // Print Member Function
  void printDisplay() {
    std::string c = " ";
    DisplayTree(root, c);
  }

  // Infix Public Member Function
  void infix() {
    InfixTraversal(root);
    std::cout << endl;
  }
};

#endif
