#ifndef HASHTABLELINEARPROBING_HPP
#define HASHTABLELINEARPROBING_HPP

class HashTableLinearProbing {
private:
    int* table;
    bool* occupied;
    int capacity;
	bool* deleted;
    int hashFunction(int key) const;
public:
    HashTableLinearProbing(int size = 1031);
    ~HashTableLinearProbing();
    void insert(int key);
    bool search(int key) const;
    void remove(int key);
    void display() const;
};

#endif // HASHTABLELINEARPROBING_HPP