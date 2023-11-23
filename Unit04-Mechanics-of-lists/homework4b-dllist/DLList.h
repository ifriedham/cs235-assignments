#pragma once

#include <iostream>
#include <string>

template<class T>
class DLList {
public:
    struct Node {
        Node *prev;
        Node *next;
        T value;

        Node(T v, Node *next = nullptr, Node *prev = nullptr) : prev(prev), next(next), value(v) {}
    };


    DLList() : listSize(0), head(nullptr), tail(nullptr) {}

    ~DLList() {
        clear();
    }

    const Node *get_head() const {
        // implement get_head here
        return head;
    }

    void push_front(T item) {
        // implement push_front here
        head = new Node(item, head); //needs destructor?
        if (listSize != 0) {
            head->next->prev = head;
        } else {
            tail = head;
        }
        listSize++;
    }

    void push_back(T item) {
        // implement push_back here
        tail = new Node(item, nullptr, tail);
        if (listSize != 0) {
            tail->prev->next = tail;
        } else {
            head = tail;
        }
        listSize++;
    }

    void insert(T item, int position) {
        // implement insert here
        if (position < 0 or position > listSize) {
            throw std::out_of_range("Invalid index");
        }
        if (position == listSize) {
            push_back(item);
        } else if (position == 0) {
            push_front(item);
        } else {
            Node *ptr = head;
            for (int i = 0; i < position; i++) {
                ptr = ptr->next;
            }
            Node *newItem = new Node(item, ptr, ptr->prev); // needs destructor
            ptr->prev = newItem;
            newItem->prev->next = newItem;
            listSize++;
        }
    }

    void pop_front() {
        // implement pop_front here
        if (listSize > 0) {
            Node *ptr = head->next;
            if (ptr) {
                ptr->prev = nullptr;
            }
            delete head;
            head = ptr;
            listSize--;
        } else {
            throw std::length_error("List is empty");
        }
    }

    void pop_back() {
        // implement pop_back here
        if (listSize > 0) {
            Node *ptr = tail->prev;
            if (ptr) {
                ptr->next = nullptr;
            }
            delete tail;
            tail = ptr;
            listSize--;
        } else {
            throw std::length_error("List is empty");
        }
    }

    void remove(int position) {
        // implement remove here
        if (position < 0 or position >= listSize) {
            throw std::out_of_range("Invalid index");
        }
        if (position == 0) pop_front();
        else if (position == listSize - 1) pop_back();
        else {
            Node *ptr = head;
            for (int i = 0; i < position; i++) {
                ptr = ptr->next;
            }

            if (ptr->next) {
                ptr->next->prev = ptr->prev;
            }
            if (ptr->prev) {
                ptr->prev->next = ptr->next;
            }
            listSize--;
            delete ptr;
        }
    }

    const T &front() const {
        // implement front here
        if (listSize > 0) {
            return head->value;
        } else {
            throw std::length_error("List is empty");
        }
    }

    const T &back() const {
        // implement back here
        if (listSize > 0) {
            return tail->value;
        } else {
            throw std::length_error("List is empty");
        }
    }

    const T &at(int index) const {
        // implement at here
        if (index < 0 or index >= listSize) {
            throw std::out_of_range("Invalid index");
        }
        if (index == listSize - 1) {
            back();
        } else if (index == 0) {
            front();
        } else {
            Node *ptr = head;
            for (int i = 0; i < index; i++) {
                ptr = ptr->next;
            }
            return ptr->value;
        }
    }

    bool contains(const T &item) const {
        // implement contains here
        Node *ptr = head;
        for (int i = 0; i < listSize; i++) {
            if (ptr->value == item) {
                return true;
            }
            ptr = ptr->next;
        }
        return false;
//        while (ptr->value != item) {
//            ptr = ptr->next;
//        }
//        if (ptr->value == item){
//            return true;
//        }
//        else if (ptr->value != item) {
//            return false;
//        }
    }

    int size() const {
        // implement size here
        return listSize;
    }

    void clear() {
        // implement clear here
        while (head) {
            Node *delNode = head;
            head = head->next;
            delNode->next = nullptr; // Set next to nullptr
            delNode->prev = nullptr; // Set prev to nullptr
            delete delNode;
        }
        listSize = 0;
    }

private:
    size_t listSize;
    Node *head;
    Node *tail;
};
