#include "header.h"
#include <vector>
#include <iostream>
using namespace std;

void insertion_sort(vector<int>& num) {
    int i, j, key;
    bool insertionNeeded = false;
    for (j = 1; j < num.size(); j++) {
        key = num[j];
        insertionNeeded = false;
        for (i = j - 1; i >= 0; i--) {
            if (key < num[i]) {
                num[i + 1] = num[i]; // larger values move right
                insertionNeeded = true;
            }
            else
                break;
        }
        if (insertionNeeded)
            num[i + 1] = key;
    }
}

int recursive_search(vector<int>& arr, int target, int index = -1, int curr = 0) {
    if (curr == arr.size()) {
        return index;
    }
    else if (arr[curr] == target) {
        return recursive_search(arr, target, curr, curr + 1);
    }
    else {
        return recursive_search(arr, target, index, curr + 1);
    }
}

template <typename Item_Type>
int linear_search(vector<Item_Type>& items, Item_Type& target, size_t pos_first) {
    if (pos_first == items.size())
        return -1; 
    if (target == items[pos_first])
        return pos_first;
    else
        return linear_search(items, target, pos_first + 1);
}