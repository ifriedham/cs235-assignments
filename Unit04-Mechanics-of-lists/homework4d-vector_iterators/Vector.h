#pragma once

#include <iostream>
#include <string>

const int INITIAL_CAPACITY = 1;

template<class T>
class Vector {
public:
    class Iterator {
        T* current;

    public:
        T& operator*() {
            // implement operator* here
            return *current;
        }

        Iterator& operator++() {
            // implement operator++ here
        }

        bool operator==(const Iterator& other) const {
            // implement operator== here
        }

        bool operator!=(const Iterator& other) const {
            // implement operator!= here
        }
    };

    Iterator begin() {
        // implement begin here
        return Iterator(data);
    }

    Iterator end() {
        // implement end here
        return Iterator(data + vSize);
    }

    // paste in your methods from the vector assignment
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
        if (position < 0 || position >= vSize) {
            throw std::out_of_range("remove index is out of bounds");
        }

        for (int i = position; i < vSize - 1; i++) {  // shifts all index's after position (like prof.'s popback())
            data[i] = data[i + 1];
        }

        --vSize;
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
        delete [] data;
        data = new T[INITIAL_CAPACITY];
        capacity = INITIAL_CAPACITY;
        vSize = 0;
    }

private:
    // paste in your data members from the vector assignment
    T *data;
    size_t capacity;
    size_t vSize;
};
