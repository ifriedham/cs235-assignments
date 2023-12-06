#pragma once

#include <list>
#include <functional>

using namespace std;

const size_t INITIAL_CAPACITY = 5;
const double MAX_FILL = 0.8;

template<class T>
class HashSet {
public:
    HashSet() {
        setSize = 0;
        capacity = INITIAL_CAPACITY;
        data = new list<T>[INITIAL_CAPACITY];
    }

    ~HashSet() {
        clear(); // (makes a new, empty set)
        delete [] data; // fully deletes that new set
    }

    bool insert(T item) {
        // implement insert here
        // return true if item was inserted, false if item was already in the set
        if (fillFactor() >= MAX_FILL) { // checks if set is too small
            grow();
        }

        if (contains(item)) { // item is already in list
            return false;
        } else { // item not found, inserting as planned
            size_t hashcode = hash<T>{}(item);
            size_t index = hashcode % capacity;

            data[index].push_front(item);
            setSize++;
            return true;
        }
    }

    bool remove(T item) {
        // implement remove here
        // return true if item was removed, false if item wasn't in the set
        if (contains(item)){ // item is in set

        } else{ // item wasn't in set
            return false;
        }
    }

    bool contains(T item) const {
        // implement contains here
        // return true if item is in the set, false otherwise
        size_t hashcode = hash<T>{}(item);
        size_t index = hashcode % capacity;
        if (data[index].size() != 0) { // checks if list is empty
            for (auto entry: data[index]) { // looks for item
                if (entry == item) return false; // item found, insert not needed
            }
            return true; //item found!
        } else { // list is empty
            return false;
        }
    }

    void clear() {
        // implement clear here
        // remove all elements from the set
        delete [] data;

        capacity = INITIAL_CAPACITY;
        data = new list<T>[INITIAL_CAPACITY]; // makes new empty set
        setSize = 0;
    }

    int size() const {
        // implement size here
        // return the number of elements in the set
        return setSize;
    }

private:
    size_t setSize;
    size_t capacity;
    list <T> *data;

    double fillFactor() {
        return static_cast<double>(setSize) / capacity;
    }

    void grow() {
        size_t oldCapacity = capacity;
        capacity = 2 * capacity + 1;
        list <T> *oldData = data;
        data = new list<T>[capacity];
        setSize = 0;

        for (size_t i = 0; i < oldCapacity; i++) { // copies old set to the new larger set
            for (auto item: oldData[i]) {
                insert(item);
            }
        }
        delete[] oldData;
    }
};
