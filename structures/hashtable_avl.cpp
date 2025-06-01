#include "hashtable_avl.hpp"

HashTableAVL::HashTableAVL(int size) : table(size), capacity(size) {} // zmieniona kolejność

int HashTableAVL::hash(int key) {
    return key % capacity;
}

void HashTableAVL::insert(int key, int value) {
    int idx = hash(key);
    table[idx].insert(key, value);
}

void HashTableAVL::remove(int key) {
    int idx = hash(key);
    table[idx].remove(key);
}

int* HashTableAVL::find(int key) {
    int idx = hash(key);
    return table[idx].find(key);
}