#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include "BST.h"
#include "MAP.h"

using namespace std;

/**
 * test of BST and MAP Implementation
*/

int main(){
    //BST of letters
    vector<string> letter_alpha = {"F","B","A","D","C","E","G","I","H"};
    
    //BST of letters
    BST<string> *word;
    word = new BST<string>;
    
    for(auto it : letter_alpha){ word->insert(it); }
    //displays BST word in Order
    word->inOrder();
    std::cout << std::endl;


    // BINARY TREE ARITHMETIC Type 2 Infix with double param
    BST<char> *newTree;
    BST<char> *secondTree;

    //"ABC*+D/", 1);
    newTree = new BST<char>("A+B-C+D*E", 2.0);
    std::cout << "First Tree: ";
    // displays arithmetic expression with balanced paranthesi
    newTree->infix();

    secondTree = new BST<char>("3+7/2", 2.0);
    std::cout << '\n' << "Second Tree: ";

    // displays BST secondTree with balanced parenthesis Infix
    secondTree->infix();
    // solves BST secondTree given arithmetic expression
    secondTree->InorderSolve();

    // BINARY TREE ARITHMETIC Infix Type 1 with int param
    BST<char> *thirdTree;
    thirdTree = new BST<char>("42*36+*", 1);
    std::cout << "\nThird Tree: ";
    thirdTree->infix();
    thirdTree->InorderSolve();
  
    
    
    return 0;
}
