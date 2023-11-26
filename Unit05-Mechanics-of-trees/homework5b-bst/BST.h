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

    BST() : root(nullptr), nodeCount(0) {} // implement the constructor here

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
        add(root, item);
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

    bool add(Node *&node, T item){
        if (node == nullptr) {
            node = new Node(item);
            nodeCount++;
            return true;
        }

        if (node->value == item){
            return false;
        }

        if (item < node->value){
            return add(node->left, item);
        } else {
            return add(node->right, item);
        }
    }

    bool remove(Node *& node, T item){
        if (node == nullptr){
            return false;
        }

        if (item < node->value){
            return remove(node->left, item);
        } else if (item > node->value){
            return remove(node->right, item);
        } else { // node with value 'item' found
            if (node->right == nullptr && node->right == nullptr){ // node is leaf
                delete node;
                node = nullptr;
            } else if (node->left == nullptr){ // node has right child
                node = node->right;
            } else if (node->right == nullptr){ // node has left child
                node = node->left;
            } else { //node has 2 children
                Node* iop = getIOP(node);
                node->value = iop->value;
                remove(node->left, iop->value);
            }
            nodeCount--;
            return true;
        }
    }

    Node* getIOP(Node* const& node) { // finds Inorder Predecessor
        Node* iop = node->left;
        while (iop->right != nullptr) {
            iop = iop->right;
        }
        return iop;
    }
};
