#include "header.h"
#include <vector>
#include <iostream>
#include <ostream>
using namespace std;

int main() {
    Queue<int> q;
    for (int i = 1; i <= 10; i++) {
        q.push(i);
    }
    cout << "Queue before: " << endl;
    q.display();
    q.move_to_rear();
    cout << "Queue after: " << endl;
    q.display();
    return 0;
}
