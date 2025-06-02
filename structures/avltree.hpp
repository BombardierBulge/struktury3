#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

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
    AVLNode* insert(AVLNode* node, int key, int value);
    AVLNode* remove(AVLNode* node, int key);
    AVLNode* minValueNode(AVLNode* node);
    int height(AVLNode* n);
    int getBalance(AVLNode* n);
    AVLNode* rotateRight(AVLNode* y);
    AVLNode* rotateLeft(AVLNode* x);
    void clear(AVLNode* node);
    AVLNode* find(AVLNode* node, int key);
    int max(int a, int b);
public:
    AVLTree();
    ~AVLTree();
    void insert(int key, int value);
    void remove(int key);
    int* find(int key);
    void clear();
};

#endif // AVL_TREE_HPP
