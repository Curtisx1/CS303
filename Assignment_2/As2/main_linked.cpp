#include "header.h"
#include "functions.h"
#include <iostream>
using namespace std;

// This program using the class I created to perform the functions on the stack.
// Unsure if this was the intended use of the class per Q2.

int main() {
    // Creating a stack object using Single_Linked_List class
    Single_Linked_List<int> stack;

    // Check if the stack is empty
    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl;

    // Get integer values from the user and push them onto the stack
    int value;
    cout << "Enter integer values to push onto the stack (enter -1 to stop):\n";
    while (true) {
        cin >> value;
        if (value == -1) break; // Stop if the user enters -1
        stack.push_back(value);
    }

    // Remove an element from the stack
    int removeVal = stack.back();
    stack.pop_back();
    cout << "Removed value from the stack: " << removeVal << endl;

    // Find the top of the stack
    if (!stack.empty())
        cout << "Top of the stack: " << stack.back() << endl;

    // Find the average value of the stack elements
    if (!stack.empty()) {
        // Calculate the sum of stack elements
        int sum = 0;
        Single_Linked_List<int>::Node* temp = stack.head;
        while (temp) {
            sum += temp->data;
            temp = temp->next;
        }
        // Calculate the average
        double average = static_cast<double>(sum) / stack.num_items;
        cout << "Average value of the stack values: " << average << endl;
    }

    return 0;
}