#include "HashTableChaining.hpp"
#include <iostream>

// Konstruktor
HashTableChaining::HashTableChaining() {
    table.resize(SIZE);
}

// Funkcja mieszająca
int HashTableChaining::hashFunction(int key) const {
    return key % SIZE;
}

// Wstawianie klucza do odpowiedniej listy
void HashTableChaining::insert(int key) {
    int index = hashFunction(key);
    table[index].push_back(key);
}

// Wyszukiwanie klucza w odpowiedniej liście
bool HashTableChaining::search(int key) const {
    int index = hashFunction(key);
    for (int element : table[index]) {
        if (element == key) return true;
    }
    return false;
}

// Wyświetlanie całej tablicy mieszającej
void HashTableChaining::display() const {
    for (int i = 0; i < SIZE; i++) {
        std::cout << i << ": ";
        for (int val : table[i]) {
            std::cout << val << " -> ";
        }
        std::cout << "nullptr\n";
    }
}