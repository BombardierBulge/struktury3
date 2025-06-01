#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <iostream>

struct AVLNode {
    int key;
    int value;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int k, int v) : key(k), value(v), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    AVLNode* root;

    int height(AVLNode* n);
    int getBalance(AVLNode* n);
    AVLNode* rotateRight(AVLNode* y);
    AVLNode* rotateLeft(AVLNode* x);
    AVLNode* insert(AVLNode* node, int key, int value);
    AVLNode* minValueNode(AVLNode* node);
    AVLNode* remove(AVLNode* node, int key);
    void clear(AVLNode* node);
    AVLNode* find(AVLNode* node, int key);

public:
    AVLTree();
    ~AVLTree();
    void insert(int key, int value);
    void remove(int key);
    int* find(int key);
};

#endif // AVL_TREE_HPP
