#pragma once

struct Node {
    Node* left;
    Node* right;
    int value;
    int height;

    Node(int v) : left(nullptr), right(nullptr), value(v), height(1) {}
};

// Hint: you might find it helpful to write an update_height function that takes
// a Node* and updates its height field based on the heights of its children
void update_height (Node* node) {

}


void promote_left(Node*& root) {
    // implement promote_left here
    auto new_root = root->right;
    root->right = new_root->left;
    new_root->left = root;
    update_height(root);
    update_height(new_root);
    root = new_root;
}

void promote_right(Node*& root) {
    // implement promote_right here
}

void rebalance(Node*& root) {
    // implement rebalance here
}
