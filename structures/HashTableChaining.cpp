#include <iostream>
#include "HashTableChaining.hpp"

// Konstruktor
HashTableChaining::HashTableChaining() {
    table.resize(SIZE);
}
// funkcja mieszająca
    int hashFunction(int key) {
        return key % SIZE;
    }

// Wstawianie klucza do odpowiedniej listy
    HashTableChaining() {
        table.resize(SIZE);
    }

// Wstawianie klucza do odpowiedniej listy
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

// Wyszukiwanie klucza w odpowiedniej liście
    bool search(int key) const {
        int index = hashFunction(key);
        for (int element : table[index]) {
            if (element == key) return true;
        }
        return false;
    }

// Wyświetlanie całej tablicy mieszającej
    void display() const {
        for (int i = 0; i < SIZE; i++) {
            std::cout << i << ": ";
            for (int val : table[i]) {
                std::cout << val << " -> ";
            }
            std::cout << "nullptr\n";
        }
    }