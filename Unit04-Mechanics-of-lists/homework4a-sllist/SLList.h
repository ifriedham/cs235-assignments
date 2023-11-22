#pragma once

template<class T>
class SLList {
public:
    struct Node {
        Node *next;
        T value;

        Node(T v) : next(nullptr), value(v) {}
    };

    SLList() : head(nullptr), sllSize(0) {
    }

    ~SLList() {
        clear();
    }

    const Node *get_head() const {
        // implement get_head here
        return head;
    }

    void push_back(T item) {
        // implement push_back here
        Node *newItem = new Node(item);



       if (head) {
           Node *nodePtr = head;
           while (nodePtr != NULL) {
               nodePtr = nodePtr->next; // move to the next node
           }
           nodePtr->next = newItem;
           sllSize++; // = sllSize + 1;
       }
       else { // no existing head
           head = newItem;
       }
    }

    void pop_back() {
        // implement pop_back here
        if (head->next) {
            Node *nodePtr = head;
            Node *prevNode = nullptr;
            while (nodePtr->next) {
                prevNode = nodePtr; // keep track of the previous node
                nodePtr = nodePtr->next; // move to the next node
            }
            prevNode->next = nullptr;
            delete nodePtr;
        }
        else { // Head is the only thing in the list
            delete head;
            head = nullptr;
        }
        sllSize--;
    }

    const T &front() const {
        // implement front here
        return head->value;
    }

    int size() const {
        // implement size here
        return sllSize;
    }

    void clear() {
        // implement clear here
        while (head) {
            Node *delNode = head;
            head = head->next;
            delete delNode;
            //sllSize--;
        }
        sllSize = 0;
    }
private:
    Node *head;
    int sllSize;
};
