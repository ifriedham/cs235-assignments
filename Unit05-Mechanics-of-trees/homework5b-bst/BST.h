#pragma once

template<class T>
class BST {
public:
    struct Node {
        Node *left;
        Node *right;
        T value;

        Node(T v) : left(nullptr), right(nullptr), value(v) {}
    };

    BST() : root(nullptr), nodeCount(0) {
        // implement the constructor here
//        root = nullptr;
//        nodeCount = 0;
    }

    ~BST() {
        // implement the destructor here
        clear();
    }

    const Node *getRootNode() const {
        // implement getRootNode here
        // return a pointer to the tree's root node
        return root;
    }

    bool insert(T item) {
        // implement insert here
        // return true if item was inserted, false if item was already in the tree
    }

    bool remove(T item) {
        // implement remove here
        // return true if item was removed, false if item wasn't in the tree
    }

    bool contains(T item) const {
        // implement contains here
        // return true if item is in the tree, false otherwise
        find(root, item);
    }

    void clear() {
        // implement clear here
        // remove all nodes from the tree
        clear(root);
        root = nullptr;
        nodeCount = 0;
    }

    int size() const {
        // implement size here
        // return the number of nodes in the tree
        return nodeCount;
    }

private:
    Node *root;
    size_t nodeCount;

    void clear(Node *&node) {
        if (node == nullptr) {
            return;
        }
        clear(node->left);
        clear(node->right);
        delete node;
    }

    bool find(Node *&node, T item) const {
        if (node == nullptr) return false;
        if (node->value == item) {
            return true;
        } else if (item < root->value) { //check left
            return find(root->left, item);
        } else { // check right
            return find(root->right, item);
        }
    }
};
