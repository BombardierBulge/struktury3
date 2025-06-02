#include <iostream>
#include "HashTableLinearProbing.hpp"

// Konstruktor
HashTableLinearProbing::HashTableLinearProbing(int size) : capacity(size) {
    table = new int[capacity];
    occupied = new bool[capacity];
    for (int i = 0; i < capacity; ++i) occupied[i] = false;
}

// Dekonstruktor
HashTableLinearProbing::~HashTableLinearProbing() {
    delete[] table;
    delete[] occupied;
}

// Funkcja mieszająca 
int HashTableLinearProbing::hashFunction(int key) const {
    return key % capacity;
}

// Wstawianie z liniowym sondowaniem
void HashTableLinearProbing::insert(int key) {
    int idx = hashFunction(key);
    int start = idx;

    // Szukamy pierwszego wolnego miejsca
    while (occupied[idx]) {
        idx = (idx + 1) % capacity;
        if (idx == start) return; // tablica pełna
    }

    table[idx] = key;
    occupied[idx] = true;
}

// Wyszukiwanie klucza z liniowym sondowaniem
bool HashTableLinearProbing::search(int key) const {
    int idx = hashFunction(key);
    int start = idx;

    // Przeszukujemy aż trafimy na pustą komórkę lub znajdziemy element
    while (occupied[idx]) {
        if (table[idx] == key) return true;
        idx = (idx + 1) % capacity;
        if (idx == start) break;
    }

    return false;
}

// Usuwanie klucza
void HashTableLinearProbing::remove(int key) {
    int idx = hashFunction(key);
    int start = idx;

    while (occupied[idx]) {
        if (table[idx] == key) {
            occupied[idx] = false;
            return;
        }
        idx = (idx + 1) % capacity;
        if (idx == start) break;
    }
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