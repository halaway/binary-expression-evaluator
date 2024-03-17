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

public:
  // Default Constructor
  Map() : root(NULL) { pairs = new KeyValuePairs<K, V>(); }

  // Constructor
  Map(K keys, V vals) {      

    pairs = new KeyValuePairs<K, V>(keys, vals);
    // root to create a tree of key value pairs
    root = new BST<KeyValuePairs<K, V> *>(pairs);
  }

  // Insert Keys and Values Member Function
  void InsertMap(K keys, V vals) {

    // Create New Entry
    KeyValuePairs<K, V> *ptr;
    ptr = new KeyValuePairs<K, V>(keys, vals);
    root->insert(ptr);
  }

  // Overridden Insert Member Function
  void InsertMap(const KeyValuePairs<K, V> rhs) {
    // Create New Entry
    KeyValuePairs<K, V> *ptr;
    ptr = new KeyValuePairs<K, V>(rhs);

    root->insert(ptr);
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

  friend std::ostream& operator<<(std::ostream& os,  Map<K, V>& map) {
    // Call a recursive function to traverse the BST and print each element
    map.printInorder();
    return os;
    }

    
};

#endif
