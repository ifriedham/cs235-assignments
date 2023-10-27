#pragma once

#include <vector>

using std::swap;

template<class T>
int medianOfThree(std::vector<T>& array, int left, int right) {
    // implement medianOfThree here
    int middle = (left + right) / 2;

    if (array[left] > array[middle]) {
        swap(array[left], array[middle]);
    }

    if (array[middle] > array[right]) {
        swap(array[middle], array[right]);
    }

    if (array[left] > array[middle]) {
        swap(array[left], array[middle]);
    }

    return middle;
}

template<class T>
int partition(std::vector<T>& array, int left, int right) {
    // implement partition here
}

template<class T>
void sort(std::vector<T>& array) {
    // implement sort here
    // hint: you'll probably want to make a recursive sort_helper function
}


