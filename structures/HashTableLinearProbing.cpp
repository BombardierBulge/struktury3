#include <iostream>
#include "HashTableLinearProbing.hpp"

// Konstruktor
HashTableLinearProbing::HashTableLinearProbing(int size) : capacity(size) {
    table = new int[capacity];
occupied = new bool[capacity];
deleted = new bool[capacity];
for (int i = 0; i < capacity; ++i) {
    occupied[i] = false;
    deleted[i] = false;
}
}
// Dekonstruktor
HashTableLinearProbing::~HashTableLinearProbing() {
    delete[] table;
    delete[] occupied;
	delete[] deleted;
}

// Funkcja mieszająca 
int HashTableLinearProbing::hashFunction(int key) const {
    return key % capacity;
}

// Wstawianie z liniowym sondowaniem
void HashTableLinearProbing::insert(int key) {
    if (search(key)) return; 
    int idx = hashFunction(key);
    int start = idx;
    do {
        if (!occupied[idx] || deleted[idx]) {
            table[idx] = key;
            occupied[idx] = true;
            deleted[idx] = false;
            return;
        }
        idx = (idx + 1) % capacity;
    } while (idx != start);

}


// Wyszukiwanie klucza z liniowym sondowaniem
bool HashTableLinearProbing::search(int key) const {
    int idx = hashFunction(key);
    int start = idx;
    do {
        if (!occupied[idx] && !deleted[idx]) return false;
        if (occupied[idx] && table[idx] == key) return true;
        idx = (idx + 1) % capacity;
    } while (idx != start);
    return false;
}

// Usuwanie klucza
void HashTableLinearProbing::remove(int key) {
    int idx = hashFunction(key);
    int start = idx;
    do {
        if (!occupied[idx] && !deleted[idx]) return;
        if (occupied[idx] && table[idx] == key) {
            occupied[idx] = false;
            deleted[idx] = true;
            return;
        }
        idx = (idx + 1) % capacity;
    } while (idx != start);
}


// Wyświetlanie całej tablicy
void HashTableLinearProbing::display() const {
    for (int i = 0; i < capacity; i++) {
        std::cout << i << ": ";
        if (occupied[i])
            std::cout << table[i];
        else
            std::cout << "puste";
        std::cout << "\n";
    }
}