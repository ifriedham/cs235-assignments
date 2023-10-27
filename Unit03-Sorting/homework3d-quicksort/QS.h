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
    int middle = medianOfThree(array,left, right);

    swap(array[left], array[middle]);  //pivot point is now array[left]

    int up = left + 1;
    int down = right;

    while (up < down) {
        while(array[up] <= array[left] || // until up points to the first element greater than the pivot value
        up < right)  // until up has reached right
        {
            up++;
        }

        while(array[down] >= array[left] || // until down points to the first element less than or equal to the pivot value
        down > left)  // until down has reached left
        {
            down--;
        }

        if (up < down){  // If up is still less than down, swap array[up] and array[down]
            swap(array[up], array[down]);
        }
    }

    swap(array[left], array[down]);  // Put the pivot back in the middle by swapping array[left] and array[down]

    return down;
}

template<class T>
void sort(std::vector<T>& array) {
    // implement sort here
    // hint: you'll probably want to make a recursive sort_helper function
}


