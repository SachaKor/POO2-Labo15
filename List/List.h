/**
 *  @file    List.h
 *  @author  Alexandra Korukova, Samuel Mayor
 *  @date    19.04.2018
 *  @version 1.0
 *
 *  @brief Doubly chained list implementation
 */

#ifndef LIST_LIST_H
#define LIST_LIST_H


#include <cstddef>
#include "Iterator.h"

template <typename T>
struct Node {
    Node<T> *prev;
    Node<T> *next;
    T data;

    Node(T& data) {
        this->data = data;
    }
};

template<typename T>
class List {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t length;

public:
    /**
     * @brief Basic constructor
     */
    List() : length(0), head(nullptr), tail(nullptr){ }

    /**
     * @brief Copy constructor
     * @param const List& list : list to copy
     */
    List(const List& list) {
        length = list.size();
    }

    /**
     * @brief Returns list size
     * @return size_t list size
     */
    size_t size() const {
        return length;
    }

    /**
     * @brief Inserts a new element to the begining of the list
     * @param const T& o : reference on element to add
     */
    void insert(T& o) {
        Node<T>* newNode = new Node<T>(o);
        Node<T>* tmp = head;
        head->prev = newNode;
        head = newNode;
        head->next = tmp;
        length++;
    }

    /**
     * @brief Inserts a new element to the end of the list
     * @param const T& o : reference on element to add
     */
    void append(const T& o) {

    }

    /**
     * @brief Removes element at given index
     * @param const size_t index : index of element to remove
     * @throws out_of_range exception
     */
    void removeAt(const size_t index) {

    }

    /**
     * @brief Removes element
     * @param const T& o : element to remove
     */
    void remove(const T& o) {

    }

    /**
     * @brief Removes element at given index
     * @param const size_t index : index of element to remove
     * @return Iterator& iterator on the begining of the list
     */
    Iterator& begin() const {

    }

    /**
     * @brief Removes element at given index
     * @param const size_t index : index of element to remove
     * @return Iterator& iterator on the end of the list
     */
    Iterator& end() const {

    }

    /**
     * @brief Finds index of given element in the list
     * @param const T& o : element to find
     */
    int find(const T& o) {

    }

    /**
     * @brief Override = operator
     * @param const List& l : list to copy
     */
    List& operator=(const List& l) {

    }

    /**
     * @brief Overrides [] operator
     * @param const size_t i : index in the list
     */
    T& operator[](const size_t i) {

    }

    /**
     * @brief inserts the values of the list into os
     * @param ostream object where the values are inserted
     * @param l the list object with the content to insert
     * @return os parameter
     */
    friend std::ostream& operator<<(std::ostream& os, const List<T>& l) {
        Node<T> *cur = l.head;
        os << "[";
        while (cur) {
            os << cur->data;
            if(cur->next) {
                os << ", ";
            }
            cur = cur->next;
        }
        os << "]";
        return os;
    }
};


#endif //LIST_LIST_H
