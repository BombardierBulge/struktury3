#ifndef HASHTABLECHAINING_HPP
#define HASHTABLECHAINING_HPP

#include <list>
#include <vector>

class HashTableChaining {
private:
    static const int SIZE = 10;
    std::vector<std::list<int>> table;

    int hashFunction(int key);

public:
    HashTableChaining();

    void insert(int key);
    bool search(int key) const;
    void display() const;
};

#endif // HASHTABLECHAINING_HPP