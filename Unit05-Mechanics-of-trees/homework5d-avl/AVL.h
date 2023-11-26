#pragma once

template<class T>
class AVL {
public:
    struct Node {
        Node *left;
        Node *right;
        T value;
        int height;

        Node(T v) : left(nullptr), right(nullptr), value(v), height(1) {}
    };

    AVL() : root(nullptr), nodeCount(0) {} // implement the contructor here

    ~AVL() {
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
        return add(root, item);
    }

    bool remove(T item) {
        // implement remove here
        // return true if item was removed, false if item wasn't in the tree
        return remove(root, item);
    }

    bool contains(T item) const {
        // implement contains here
        // return true if item is in the tree, false otherwise
        return find(root, item);
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
    int nodeCount;

    void clear(Node *&node) {
        if (node == nullptr) {
            return;
        }
        clear(node->left);
        clear(node->right);
        delete node;
    }

    bool find(const Node *node, T item) const {
        if (node == nullptr) return false;
        if (node->value == item) {
            return true;
        } else if (item < node->value) { // check left
            return find(node->left, item);
        } else { // check right
            return find(node->right, item);
        }
    }

    bool add(Node *&node, T item) {
        if (node == nullptr) {
            node = new Node(item);
            nodeCount++;
            return true;
        }

        if (node->value == item) {
            return false;
        }

        bool changed = false;
        if (item < node->value) {
            changed = add(node->left, item);
        } else {
            changed = add(node->right, item);
        }
        if (changed) {
            update_height(node);
            rebalance(node);
        }
        return changed;
    }

    bool remove(Node *&node, T item) {
        if (node == nullptr) {
            return false;
        }

        if (item < node->value) {
            return remove(node->left, item);
        } else if (item > node->value) {
            return remove(node->right, item);
        } else { // node with value 'item' found
            if (node->left == nullptr && node->right == nullptr) { // node is leaf
                delete node;
                node = nullptr;
            } else if (node->left == nullptr) { // node has right child
                node = node->right;
            } else if (node->right == nullptr) { // node has left child
                node = node->left;
            } else { //node has 2 children
                Node *iop = getIOP(node);
                node->value = iop->value;
                remove(node->left, iop->value);
            }
            update_height(node);
            rebalance(node);
            nodeCount--;
            return true;
        }
    }

    int get_height(Node *&node) {
        return (node == nullptr) ? 0 : node->height;
    }

    void update_height(Node *&node) {
        node->height = std::max(get_height(node->left), get_height(node->right)) + 1;
    }

    int get_balance(Node *&node) {
        return get_height(node->right) - get_height(node->left);
    }

    void promote_left(Node *&root) {
        // implement promote_left here
        auto new_root = root->left;
        root->left = root->left->right;
        new_root->right = root;
        root = new_root;
        update_height(root->right);
        update_height(root);
    }

    void promote_right(Node *&root) {
        // implement promote_right here
        auto new_root = root->right;
        root->right = root->right->left;
        new_root->left = root;
        root = new_root;
        update_height(root->left);
        update_height(root);
    }

    void rebalance_negative(Node *&node) {
        // Is the sign of the left child positive?
        if (get_balance(node->left) > 0) {
            // Promote left's right child
            promote_right(node->left);
        }
        // Now rotate right
        promote_left(node);
    }

    void rebalance_positive(Node *&node) {
        // Is the sign of the right child negative?
        if (get_balance(node->right) < 0) {
            // Promote right's left child
            promote_left(node->right);
        }
        // Now rotate left
        promote_right(node);
    }


    void rebalance(Node *&root) {
        // implement rebalance here
        int balance = get_balance(root);

        if (balance > 1) {
            rebalance_positive(root);
        } else if (balance < -1) {
            rebalance_negative(root);
        }

        update_height(root);
    }


};
