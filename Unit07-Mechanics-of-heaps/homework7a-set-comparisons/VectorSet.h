#pragma once

#include <vector>

template<class T>
class VectorSet {
private:
    std::vector<T> myVec;
public:
    bool contains(T item) const {
        // implement contains here
        for (const T& itemInVec : myVec) {
            if (itemInVec == item) {
                return true;
            }
        }
        return false;
    }

// return true if item is in the set and false if not
    bool insert(T item) {
        // implement insert here
        if (contains(item)) {
            return false;
        } else {
            myVec.push_back(item);
            return true;
        }
        // return true if item is inserted and false if item is already in the
        // set
    }

    bool remove(T item) {
        // implement remove here
        if (contains(item)) {
            for (auto i = myVec.begin(); i != myVec.end(); i++) {
                if (*i == item) {
                    myVec.erase(i);
                    return true;
                }
            }

        } else {
            return false;
        }
        // return true if item is removed and false if item wasn't in the set
    }

    int size() const {
        // implement size here
        return myVec.size();
        // return the number of items in the set
    }

    bool empty() const {
        // implement empty here
        if (myVec.empty()) {
            return true;
        } else {
            return false;
        }
        // return true if the set is empty and return false otherwise
    }

    void clear() {
        // implement clear here
        myVec.clear();
        // remove all items from the set
    }
};
