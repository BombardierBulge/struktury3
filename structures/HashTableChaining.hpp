#ifndef HASHTABLECHAINING_HPP
#define HASHTABLECHAINING_HPP

class LinkedList {
public:
    struct Node {
        int key;
        Node *next;
        Node(int k) : key(k), next(nullptr) {}
    };
    Node *head;
    LinkedList();
    ~LinkedList();
    bool search(int key) const; // sprawdza czy klucz istnieje w liście
    void display() const;       // wyświetla wszystkie klucze w liście
    bool insert(int key);       // wstawia klucz do listy, jeśli go nie ma
    void insertDirect(int key); // wstawia klucz bez sprawdzania duplikatów
    bool remove(int key);       // usuwa klucz z listy
    Node *getHead() const { return head; } // zwraca wskaźnik na początek listy
};

class HashTableChaining {
private:
    int capacity;
    int count = 0;
    const double LOAD_FACTOR_THRESHOLD = 0.75;
    LinkedList **table;
    int hashFunction(int key) const; // oblicza indeks tablicy dla klucza
    void resize(int newCapacity);    // zmienia rozmiar tablicy

public:
    HashTableChaining(int size = 1031);
    ~HashTableChaining();
    void insert(int key);        // wstawia klucz do tablicy
    bool search(int key) const;  // sprawdza czy klucz istnieje w tablicy
    void remove(int key);        // usuwa klucz z tablicy
    void display() const;        // wyświetla całą tablicę
};

#endif