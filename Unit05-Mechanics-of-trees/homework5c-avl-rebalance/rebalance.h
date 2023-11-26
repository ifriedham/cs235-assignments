#pragma once

struct Node {
    Node *left;
    Node *right;
    int value;
    int height;

    Node(int v) : left(nullptr), right(nullptr), value(v), height(1) {}
};

// Hint: you might find it helpful to write an update_height function that takes
// a Node* and updates its height field based on the heights of its children
int get_height(Node *&node) {
    return (node == nullptr) ? 0 : node->height;
}

void update_height(Node *&node) {
    node->height = std::max(get_height(node->left), get_height(node->right)) + 1;
}

int get_balance (Node *&node){
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