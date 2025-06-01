#ifndef HASHTABLE_AVL_HPP
#define HASHTABLE_AVL_HPP

#include "avltree.hpp"
#include <vector>

class HashTableAVL {
private:
    std::vector<AVLTree> table;
    int capacity;

    int hash(int key);

public:
    HashTableAVL(int size = 1031); // liczba pierwsza
    void insert(int key, int value);
    void remove(int key);
    int* find(int key);
};

#endif // HASHTABLE_AVL_HPP