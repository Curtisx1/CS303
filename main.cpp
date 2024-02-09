#include <iostream>
#include <stdexcept>
#include <fstream>
#include "functions.h"

using namespace std;

int main() {
    ArrayOperations array;
    ifstream inputFile("A1input.txt");

    if (!inputFile) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    int num;
    while (inputFile >> num) {
        array.add(num);
    }

    // Searches for a number from input. Returns the index.
    int searchNum = 0;
    cout << "Enter a number to search: ";
    cin >> searchNum;

    int index = array.find(searchNum);
    if (index != -1)
        cout << "Number " << searchNum << " found at index: " << index << endl;
    else
        cout << "Number " << searchNum << " not found." << endl;

    // Modifying number at chosen index. Returns old value and new value
    try {
        int indexNum = 0;
        cout << "Enter index to modify: ";
        cin >> indexNum;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Invalid input for index. Integer values only");
        }

        int valueNum = 0;
        cout << "Enter new value: ";
        cin >> valueNum;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Invalid input for value. Integer values only.");
        }

        pair<int, int> values = array.modify(indexNum, valueNum);
        int oldValue = values.first;
        int newValue = values.second;

        if (oldValue != -1) {
            cout << "Old value at index " << indexNum << ": " << oldValue << "." << endl;
            cout << "New value at index " << indexNum << ": " << newValue << "." << endl;
        }
        else {
            cout << "Index is out of bounds." << endl;
        }
    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
        cout << "Please try again." << endl;
    }

    // Adding an integer to the array from input
    try {
        int addNum = 0;
        cout << "Enter an integer to add to the array: ";
        cin >> addNum;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Invalid input for value. Integer values only.");
        }
        array.add(addNum);
        cout << "Added integer: " << addNum << endl;
    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
        cout << "Please try again." << endl;
    }

    // By Index: Replacing an integer with 0 or removing from the array. Entering 1 deletes the value from the array.
    int chosenIndex = 0;
    cout << "Enter the index to remove or replace with 0: ";
    cin >> chosenIndex;

    int removeTF = 0;
    cout << "Do you want to remove the value at index " << chosenIndex << "?" << endl;
    cout << "Enter 1 for yes or 2 for no: " << endl;
    cin >> removeTF;

    if (removeTF == 1) {
        array.replaceOrRemove(chosenIndex, true);
    }
    else if (removeTF == 2) {
        array.replaceOrRemove(chosenIndex, false);
    }

    return 0;
}
