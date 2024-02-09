#include <iostream>
#include <utility>
#include <fstream>
using namespace std;

const int MAX_SIZE = 1000;

class ArrayOperations {
private:
    int arr[MAX_SIZE];
    int size;

public:
    ArrayOperations() : size(0) {
        for (int i = 0; i < MAX_SIZE; ++i) {
            arr[i] = 0;
        }
    }

    // Function to check if a certain integer exists in the array
    int find(int num) {
        for (int i = 0; i < size; ++i) {
            if (arr[i] == num)
                return i;
        }
        return -1;
    }

    // Function to modify the value of an integer and return both the old and new value
     pair<int, int> modify(int index, int newValue) {
        pair<int, int> result;
        if (index >= 0 && index < size) {
            result.first = arr[index];
            arr[index] = newValue;
            result.second = newValue;
        }
        else {
            result.first = -1;
            result.second = -1;
        }
        return result;
    }

    // Function to add a new integer to the end of the array
    void add(int num) {
        if (size < MAX_SIZE)
            arr[size++] = num;
        else
            cout << "Array is full. Cannot add more elements." << endl;
    }

    // Function to replace the value at an index with 0 or remove the integer altogether
    void replaceOrRemove(int index, bool remove = true) {
        if (index >= 0 && index < size) {
            if (remove) {
                for (int i = index; i < size - 1; ++i)
                    arr[i] = arr[i + 1];
                --size;
                cout << "Removed " << index << "." << endl;
            }
            else {
                arr[index] = 0;
                cout << "Replaced " << index << " with 0." << endl;
            }
        }
        else {
            cout << "Index is out of bounds." << endl;
        }
    }
};
