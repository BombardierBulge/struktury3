#include "HashTableChaining.hpp"
#include <iostream>

// LinkedList
LinkedList::LinkedList() : head(nullptr) {}
LinkedList::~LinkedList() { while (head) { Node* tmp = head; head = head->next; delete tmp; } } 
void LinkedList::insert(int key) {
    Node* n = new Node(key);
    n->next = head;
    head = n;
}
bool LinkedList::search(int key) const {
    for (Node* n = head; n; n = n->next)
        if (n->key == key) return true;
    return false;
}
void LinkedList::remove(int key) {
    Node** cur = &head;
    while (*cur) {
        if ((*cur)->key == key) {
            Node* tmp = *cur;
            *cur = (*cur)->next;
            delete tmp;
            return;
        }
        cur = &((*cur)->next);
    }
}

// Konstruktor
HashTableChaining::HashTableChaining(int size) : capacity(size) {
    table = new LinkedList*[capacity];
    for (int i = 0; i < capacity; ++i) table[i] = new LinkedList();
}

// Destruktor
HashTableChaining::~HashTableChaining() {
    for (int i = 0; i < capacity; ++i) delete table[i];
    delete[] table;
}

// Funkcja mieszająca
int HashTableChaining::hashFunction(int key) const {
    return key % capacity;
}

// Wstawianie klucza do odpowiedniej listy
void HashTableChaining::insert(int key) {
    table[hashFunction(key)]->insert(key);
}

// Wyszukiwanie klucza w odpowiedniej liście
bool HashTableChaining::search(int key) const {
    return table[hashFunction(key)]->search(key);
}

// Usuwanie klucza z odpowiedniej listy
void HashTableChaining::remove(int key) {
    table[hashFunction(key)]->remove(key);
}

// Wyświetlanie całej tablicy mieszającej
void HashTableChaining::display() const {
    for (int i = 0; i < capacity; i++) {
        std::cout << i << ": ";
        for (Node* n = table[i]->getHead(); n; n = n->next) {
            std::cout << n->key << " -> ";
        }
        std::cout << "nullptr\n";
    }
}