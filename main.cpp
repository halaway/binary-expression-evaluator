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


    // BINARY TREE KV Insert

    std::cout<<"\nCreating Map using BST: First Method"<<std::endl;
    BST<KeyValuePairs<int, int> > treeMap;

    // Example Key Pairs
    KeyValuePairs<int, int> first(4,5);
    KeyValuePairs<int, int> second(3,6);
    KeyValuePairs<int, int> third(7,8);

    treeMap.insert(first);
    treeMap.insert(second);
    treeMap.insert(third);

    // Displaying Pairs
    treeMap.inOrder();


    std::cout<<"\n\nCreating Map using Class implementation: Second Method"<<std::endl;
    // USING MAP CLASS
    Map<int, int> numbers;
    Map<int, int>iter;


    //Example Using Subscript
    numbers[3] = 6;
    numbers[4] = 5;
    numbers[7] = 8;

    std::cout<<numbers<<std::endl;


    std::cout<<"Using Operators"<<std::endl;

    for(int i = 0; i < 15; i++)
        iter[i]++;

    iter.InsertMap(8,4);

    std::cout<<iter<<endl;
    


    return 0;
}
