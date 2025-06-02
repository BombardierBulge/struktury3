#ifndef HASHTABLE_AVL_HPP
#define HASHTABLE_AVL_HPP

#include "avltree.hpp"

class HashTableAVL {
private:
    AVLTree** table;
    int capacity;
    int hash(int key);
public:
    HashTableAVL(int size = 1031);
    ~HashTableAVL();
    void insert(int key, int value);
    void remove(int key);
    int* find(int key);
};

#endif