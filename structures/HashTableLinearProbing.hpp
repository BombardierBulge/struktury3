#ifndef HASHTABLELINEARPROBING_HPP
#define HASHTABLELINEARPROBING_HPP

#include <vector>

class HashTableLinearProbing {
private:
    static const int SIZE = 10;
    std::vector<int> table;
    std::vector<bool> occupied;

    int hashFunction(int key) const;

public:
    HashTableLinearProbing();

    void insert(int key);
    bool search(int key) const;
    void display() const;
};

#endif // HASHTABLELINEARPROBING_HPP