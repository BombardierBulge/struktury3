#include <iostream>
#include "HashTableLinearProbing.hpp"

// Konstruktor
HashTableLinearProbing::HashTableLinearProbing() {
    table.resize(SIZE, -1);       
    occupied.resize(SIZE, false); 
}

// Funkcja mieszająca 
int HashTableLinearProbing::hashFunction(int key) const {
    return key % SIZE;
}

// Wstawianie z liniowym sondowaniem
void HashTableLinearProbing::insert(int key) {
    int index = hashFunction(key);
    int startIndex = index;

    // Szukamy pierwszego wolnego miejsca
    while (occupied[index]) {
        index = (index + 1) % SIZE;
        if (index == startIndex) {
            std::cout << "Hash table is full!\n";
            return;
        }
    }

    table[index] = key;
    occupied[index] = true;
}

// Wyszukiwanie klucza z liniowym sondowaniem
bool HashTableLinearProbing::search(int key) const {
    int index = hashFunction(key);
    int startIndex = index;

    // Przeszukujemy aż trafimy na pustą komórkę lub znajdziemy element
    while (occupied[index]) {
        if (table[index] == key) return true;
        index = (index + 1) % SIZE;
        if (index == startIndex) break;
    }

    return false;
}

// Wyświetlanie całej tablicy
void HashTableLinearProbing::display() const {
    for (int i = 0; i < SIZE; i++) {
        std::cout << i << ": ";
        if (occupied[i])
            std::cout << table[i];
        else
            std::cout << "empty";
        std::cout << "\n";
    }
}