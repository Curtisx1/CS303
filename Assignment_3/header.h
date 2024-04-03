#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
class Queue {
private:
    Node<T>* front;
    Node<T>* rear;
    int size;

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    bool empty() {
        return size == 0;
    }

    int get_size() {
        return size;
    }

    void push(T data) {
        Node<T>* temp = new Node<T>(data);
        if (rear == nullptr) {
            front = rear = temp;
            size++;
            return;
        }
        rear->next = temp;
        rear = temp;
        size++;
    }

    void pop() {
        if (front == nullptr) {
            return;
        }
        Node<T>* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        size--;
    }

    T get_front() {
        if (front == nullptr) {
            return T();
        }
        return front->data;
    }

    void move_to_rear() {
        if (front == nullptr || front == rear) {
            return;
        }
        Node<T>* temp = front;
        front = front->next;
        rear->next = temp;
        temp->next = nullptr;
        rear = temp;
    }

    void display() {
        Node<T>* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

void insertion_sort(vector<int>& num);

int recursive_search(vector<int>& arr, int target, int index = -1, int curr = 0);

template <typename Item_Type>
int linear_search(vector<Item_Type>& items, Item_Type& target, size_t pos_first);