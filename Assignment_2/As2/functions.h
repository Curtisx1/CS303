#include "header.h"
#include <stdexcept>

template <typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

template <typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    head = new Node(item, head);
    if (!tail) tail = head;
    ++num_items;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    if (!head) {
        head = new Node(item);
        tail = head;
    }
    else {
        tail->next = new Node(item);
        tail = tail->next;
    }
    ++num_items;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
    --num_items;
    if (!head) tail = nullptr;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
    if (!head) return;
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    }
    else {
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }
    --num_items;
}

template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::front() const {
    if (!head) throw std::out_of_range("List is empty");
    return head->data;
}

template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::back() const {
    if (!tail) throw std::out_of_range("List is empty");
    return tail->data;
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
    return num_items == 0;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
    if (index >= num_items) {
        push_back(item);
        return;
    }
    if (index == 0) {
        push_front(item);
        return;
    }
    Node* temp = head;
    for (size_t i = 0; i < index - 1; ++i) {
        temp = temp->next;
    }
    Node* new_node = new Node(item, temp->next);
    temp->next = new_node;
    ++num_items;
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
    if (index >= num_items) return false;
    if (index == 0) {
        pop_front();
        return true;
    }
    Node* temp = head;
    for (size_t i = 0; i < index - 1; ++i) {
        temp = temp->next;
    }
    Node* to_delete = temp->next;
    temp->next = to_delete->next;
    if (to_delete == tail) tail = temp;
    delete to_delete;
    --num_items;
    return true;
}

template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) {
    Node* temp = head;
    size_t index = 0;
    while (temp) {
        if (temp->data == item) return index;
        temp = temp->next;
        ++index;
    }
    return num_items;
}
