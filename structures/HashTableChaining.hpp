#ifndef HASHTABLECHAINING_HPP
#define HASHTABLECHAINING_HPP

struct Node {
    int key;
    Node* next;
    Node(int k) : key(k), next(nullptr) {}
};

class LinkedList {
    Node* head;
public:
    LinkedList();
    ~LinkedList();
    void insert(int key);
    bool search(int key) const;
    void remove(int key);
    void display() const;
    Node* getHead() const { return head; } 
};

class HashTableChaining {
private:
    int capacity;
    LinkedList** table;
    int hashFunction(int key) const;
public:
    HashTableChaining(int size = 1031);
    ~HashTableChaining();
    void insert(int key);
    bool search(int key) const;
    void remove(int key);
    void display() const; 
};
#endif // HASHTABLECHAINING_HPP