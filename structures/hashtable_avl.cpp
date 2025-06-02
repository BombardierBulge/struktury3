#include "hashtable_avl.hpp"

HashTableAVL::HashTableAVL(int size) : capacity(size) {
    table = new AVLTree*[capacity];
    for (int i = 0; i < capacity; ++i) table[i] = new AVLTree();
}

HashTableAVL::~HashTableAVL() {
    for (int i = 0; i < capacity; ++i) delete table[i];
    delete[] table;
}

int HashTableAVL::hash(int key) { return key % capacity; }

void HashTableAVL::insert(int key, int value) { table[hash(key)]->insert(key, value); }

void HashTableAVL::remove(int key) { table[hash(key)]->remove(key); }

int* HashTableAVL::find(int key) { return table[hash(key)]->find(key); }