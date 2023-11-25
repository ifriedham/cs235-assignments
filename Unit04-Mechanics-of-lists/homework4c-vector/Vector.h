#pragma once

#include <iostream>
#include <string>

const int INITIAL_CAPACITY = 1;

template<class T>
class Vector {
public:
    Vector() {
        data = new T[INITIAL_CAPACITY];
        capacity = INITIAL_CAPACITY;
        vSize = 0;
    }

    ~Vector() {
        clear();
        delete[] data;
    }

    void grow() {
        size_t newSize = capacity * 2;
        T *newArray = new T[newSize];
        for (size_t i = 0; i < vSize; i++) {
            newArray[i] = data[i];
        }
        delete [] data;
        data = newArray;
        capacity = newSize;
    }

    void push_back(T item) {
        // implement push_back here
        if (vSize == capacity){
            grow();
        }
        data[vSize++] = item;
    }

    void insert(T item, int position) {
        // implement insert here
        if (position < 0 || position > vSize) {
            throw std::out_of_range("Insert index is out of bounds");
        }

        if (vSize == capacity) {
            grow();
        }

        for (int i = vSize; i > position; i--) {
            data[i] = data[i - 1];
        }

        data[position] = item;
        ++vSize;
    }

    void remove(int position) {
        // implement remove here
    }

    T& operator[](int index) {
        // implement operator[] here
        if (index < 0 || index >= vSize) {
            throw std::out_of_range("Your index is out of bounds");
        }
        return data[index];
    }

    int size() const {
        // implement size here
        return vSize;
    }

    void clear() {
        // implement clear here
    }

private:
    T *data;
    size_t capacity;
    size_t vSize;
};
