#include <iostream>
#include <vector>
using namespace std;

// Q2 main, unsure if this was the requirement and that we were NOT meant to use the class we wrote.

int main() {
    // Creating a stack object using vector
    vector<int> stack;

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
        for (int item : stack) {
            sum += item;
        }
        // Calculate the average
        double average = static_cast<double>(sum) / stack.size();
        cout << "Average value of the stack values: " << average << endl;
    }

    return 0;
}
