#include "HashTableChaining.hpp"
#include <iostream>

// linked list

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    while (head) {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
}

bool LinkedList::insert(int key) {
    if (search(key))
        return false;
    Node *n = new Node(key);
    n->next = head;
    head = n;
    return true;
}

void LinkedList::insertDirect(int key) {
    Node *n = new Node(key);
    n->next = head;
    head = n;
}

bool LinkedList::search(int key) const {
    for (Node *n = head; n; n = n->next)
        if (n->key == key)
            return true;
    return false;
}

bool LinkedList::remove(int key) {
    Node **cur = &head;
    while (*cur) {
        if ((*cur)->key == key) {
            Node *tmp = *cur;
            *cur = (*cur)->next;
            delete tmp;
            return true;
        }
        cur = &((*cur)->next);
    }
    return false;
}

void LinkedList::display() const {
    for (Node *n = head; n; n = n->next)
        std::cout << n->key << " -> ";
    std::cout << "nullptr";
}

// hash table chaining

HashTableChaining::HashTableChaining(int size) : capacity(size), count(0) {
    table = new LinkedList *[capacity];
    for (int i = 0; i < capacity; ++i)
        table[i] = new LinkedList();
}

HashTableChaining::~HashTableChaining() {
    for (int i = 0; i < capacity; ++i)
        delete table[i];
    delete[] table;
}

int HashTableChaining::hashFunction(int key) const {
    return key % capacity;
}

void HashTableChaining::resize(int newCapacity) {
    // tworzy nową tablicę
    LinkedList **newTable = new LinkedList *[newCapacity];
    for (int i = 0; i < newCapacity; ++i)
        newTable[i] = new LinkedList();
    int oldCapacity = capacity;
    LinkedList **oldTable = table;
    table = newTable;
    capacity = newCapacity;
    // przenosi elementy ze starej tablicy
    for (int i = 0; i < oldCapacity; ++i) {
        LinkedList::Node *current = oldTable[i]->getHead();
        while (current != nullptr) {
            int key = current->key;
            int newIndex = hashFunction(key);
            newTable[newIndex]->insertDirect(key);
            current = current->next;
        }
    }
    // usuwa starą tablicę
    for (int i = 0; i < oldCapacity; ++i)
        delete oldTable[i];
    delete[] oldTable;
}

void HashTableChaining::insert(int key) {
    int index = hashFunction(key);
    if (table[index]->insert(key)) {
        count++;
        if (static_cast<double>(count) / capacity > LOAD_FACTOR_THRESHOLD)
            resize(2 * capacity);
    }
}

bool HashTableChaining::search(int key) const {
    return table[hashFunction(key)]->search(key);
}

void HashTableChaining::remove(int key) {
    int index = hashFunction(key);
    if (table[index]->remove(key))
        count--;
}

void HashTableChaining::display() const {
    for (int i = 0; i < capacity; i++) {
        std::cout << i << ": ";
        table[i]->display();
        std::cout << "\n";
    }
}