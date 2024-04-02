#ifndef MAP_H
#define MAP_H

#include "BST.h"
#include <iostream>
#include <vector>

using namespace std;

/*
 * Creates a Map of Key Value Pairs
 * using a BST implementation
 */

// Map Struct Key Values Pairs
template <typename K, typename V> struct KeyValuePairs {
  // Key
  K keyVal;
  // Value
  V valueVal;

public:
  KeyValuePairs() {}
  KeyValuePairs(const K &key, const V &val) : keyVal(key), valueVal(val) {}
  // overloaded ostream operator

  // Overloaded > operator
  friend bool operator>(const KeyValuePairs<K, V> &rhs,
                        const KeyValuePairs<K, V> &lhs) {
    return rhs.keyVal > lhs.keyVal;
  }

  // Overloaded < operator
  friend bool operator<(const KeyValuePairs<K, V> &rhs,
                        const KeyValuePairs<K, V> &lhs) {
    return rhs.keyVal < lhs.keyVal;
  }

  // Overloaded == operator
  friend bool operator==(const KeyValuePairs<K, V> &rhs,
                         const KeyValuePairs<K, V> &lhs) {
    return rhs.keyVal == lhs.keyVal;
  }

  // operator + (const KeyValuePairs)
  friend K operator+(const KeyValuePairs<K, V> &rhs,
                     const KeyValuePairs<K, V> &lhs) {
    return rhs.keyVal + lhs.keyVal;
  }

  // operator - (const KeyValuePairs)
  friend K operator-(const KeyValuePairs<K, V> &rhs,
                     const KeyValuePairs<K, V> &lhs) {
    return rhs.keyVal - lhs.keyVal;
  }
  // operator * (const KeyValuePairs)
  friend K operator*(const KeyValuePairs<K, V> &rhs,
                     const KeyValuePairs<K, V> &lhs) {
    return rhs.keyVal * lhs.keyVal;
  }

  // operator - (const KeyValuePairs)
  friend K operator/(const KeyValuePairs<K, V> &rhs,
                     const KeyValuePairs<K, V> &lhs) {
    return rhs.keyVal / lhs.keyVal;
  }

  // Overloaded Ostream operator
  friend std::ostream &operator<<(std::ostream &os,
                                  const KeyValuePairs<K, V> &rhs) {
    os << "(" << rhs.keyVal << "," << rhs.valueVal << ") ";
    return os;
  }


};

// Map class class Comparable
template <typename K, typename V> class Map {
private:
  // root to BST tree of type KeyValuePairs
  BST<KeyValuePairs<K, V> *> *root;
  // tNode<KeyValuePairs<K, V>  > *root;

  // keyValuePairs
  KeyValuePairs<K, V> *pairs;

  // overloaded [] operator  
  V& searchInsert(BST<KeyValuePairs<K, V> *> *root, const K& key){
    
    // Creating key to search before insertion
    KeyValuePairs<K,V> *kv = new KeyValuePairs<K,V>(key,key);
    
    // Search using BST  
    tNode<KeyValuePairs<K, V> *> *foundNode = root->searchP(kv);

    if( foundNode != nullptr )
      return (foundNode->item)->valueVal;


    else{
      // Create new key value pair to insert with l-value reference
      KeyValuePairs<K,V> *kv = new KeyValuePairs<K,V>(key,V());

      root->insert(kv);
      return kv->valueVal;
    }
  }

public:
  // Default Constructor
  Map() : root(nullptr), pairs(nullptr) { pairs = new KeyValuePairs<K, V>();}

  // Constructor
  Map(K keys, V vals) : root(nullptr), pairs(nullptr) {
    pairs = new KeyValuePairs<K, V>(keys, vals);
    root = new BST<KeyValuePairs<K, V> *>();
    root->insert(pairs);
}

  // Insert Keys and Values Member Function
  void InsertMap(K keys, V vals) {

    pairs = new KeyValuePairs<K, V>(keys,vals); 
     if(root == nullptr ){
      root = new BST<KeyValuePairs<K, V> *>();
    }
    root->insertKV(pairs);
  }

  // Overridden Insert Member Function
  void InsertMap(const KeyValuePairs<K, V> rhs) {
    // Create New Entry
    KeyValuePairs<K, V> *ptr;
    ptr = new KeyValuePairs<K, V>(rhs);
    
    if(root == nullptr ){
      root = new BST<KeyValuePairs<K, V> *>();
    }

    //if( root-> )
    root->insertKV(ptr);
    
  }

   //Overloaded [] Operator 
  V& operator[](const K &key){

    if(root == nullptr ){
      root = new BST<KeyValuePairs<K, V> *>();
    }

    return searchInsert(root, key);
  } 

  //Finding Keys Print
  void printFind(const K& key ){

    KeyValuePairs<K,V> *findKey = new KeyValuePairs<K,V>(key, V());
    root->printFind(findKey);
  }

  bool findValue(const KeyValuePairs<K,V>& rhs){

    //Create new pair
    KeyValuePairs<K,V> *findKey = new KeyValuePairs<K,V>(rhs);
    
    //Check if root is empty
     if(root == nullptr ){
      root = new BST<KeyValuePairs<K, V> *>();
    }
    bool found = root->printValueFind(findKey);
    

    return found;
  }   

  // Overloaded print find using Key Value Pairs
  void printFind(const KeyValuePairs<K,V> &rhs){

    KeyValuePairs<K,V> *findKey = new KeyValuePairs<K,V>(rhs);
    if(root == nullptr ){
      root = new BST<KeyValuePairs<K, V> *>();
    }
    root->printFind(findKey);


  }

  // Inorder Key Pairs
  //void InorderKeyPairs() { root->inOrder(); }

  // Inorder Key Value Pairs Print
  void printInorder() { root->printInOrder(); }

  // Overloaded ostream operator for Map Objects
  // friend std::ostream &operator<<(std::ostream &os, const Map<K, V> &rhs) {
  //   os << rhs.keyVal;
  //   //os << *(rhs.root);
  //   return os;
  // }

  // Checking Map Root Status
  bool empty(){
    return root == nullptr;
  }

  friend std::ostream& operator<<(std::ostream& os,  Map<K, V>& map) {

    if ( map.empty() ) {
        os << "Empty map";
    } else {
    // Call a recursive function to traverse the BST and print each element
      map.printInorder();
      
    }
    return os;
  }

    
};

#endif
