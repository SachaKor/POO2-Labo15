//
// Created by samuel on 4/19/18.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H


#include <cstddef>
#include "Iterator.h"

template <typename T>
struct Node {
    Node *prev;
    Node *next;
    T data;
};

template<typename T>
class List {
private:
    T head;
public:
    List();
    List(const List& list);
    size_t size() const;
    void insert(const T& o);
    void append(const T& o);
    void removeAt(size_t index);
    void remove(const T& o);
    Iterator& begin() const;
    Iterator& end() const;
    int find(const T& o);
    List& operator=(const List& l);
    T& operator[](const size_t i);
};


#endif //LIST_LIST_H
