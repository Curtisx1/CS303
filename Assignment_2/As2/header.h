#ifndef HEADER_H
#define HEADER_H

#include <cstddef> // for size_t

template <typename Item_Type>
class Single_Linked_List {
public:
    struct Node {
        Item_Type data;
        Node* next;
        Node(const Item_Type& d, Node* n = nullptr) : data(d), next(n) {}
    };

    Node* head;
    Node* tail;
    size_t num_items;
    Single_Linked_List();
    ~Single_Linked_List();

    void push_front(const Item_Type& item);
    void push_back(const Item_Type& item);
    void pop_front();
    void pop_back();
    Item_Type front() const;
    Item_Type back() const;
    bool empty() const;
    void insert(size_t index, const Item_Type& item);
    bool remove(size_t index);
    size_t find(const Item_Type& item);
};

#endif 
