/**
 *  @file    List.h
 *  @author  Alexandra Korukova, Samuel Mayor
 *  @date    19.04.2018
 *  @version 1.0
 *
 *  @brief Doubly chained list implementation
 *  This class implements a doubly chained list. constant
 *  list won't allow any change on the list.
 *  Iterator constant and not constant can be instanciated
 *  with begin() and end() methods to iterate threw the list
 */

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include <iostream>
#include <cstddef>
#include <vector>

template <typename T>
struct Node {
    Node<T> *prev;
    Node<T> *next;
    T data;

    /**
     * default contructor of Node struct
     * it sets previous and next node to nullptr
     */
    Node() {
        prev = next = nullptr;
    }

    /**
     * Node constructor with data
     * @param data
     */
    Node(const T& data) {
        this->data = data;
    }
};

template <typename T>
class List {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t length;

public:
    class Iterator {
    protected:
        Node<T>* node;
    public:

        /**
         * Default constructor
         */
        Iterator() {}

        /**
         * Constructor with start Node
         * @param node
         */
        Iterator(Node<T>* node) : node(node){}

        /**
         * Check if node has a next node
         * @return bool of result
         */
        bool hasNext() {
            return node->next != nullptr;
        }

        /**
         * Check if node has a previous node
         * @return bool of result
         */
        bool hasPrevious() {
            return node->prev != nullptr;
        }

        /**
         * return this Iterator on next node
         * @return this Iterator on next node
         * @throw out_of_range exception
         */
        Iterator next() {
            if (!hasNext())
                throw std::out_of_range("Out of range");
            node = node->next;
            return *this;
        }

        /**
         * return this Iterator on previous node
         * @return this Iterator on previous node
         * @throw out_of_range exception
         */
        Iterator previous() {
            if (!hasPrevious())
                throw std::out_of_range("Out of range");
            node = node->prev;
            return *this;
        }

        /**
         * return node of the iterator
         * @return current node
         */
        Node<T>* getNode() {
            return node;
        }

        /**
         * overload == operator to compare two iterators
         * @param right Other iterator to compare with
         * @return bool of wether they are equal or not
         */
        bool operator==(const Iterator& right) const {
            return this->node == right.node;
        }

        /**
         * overload != operator to compare two iterators
         * @param right Other iterator to compare with
         * @return bool of wether they are equal or not
         */
        bool operator!=(const Iterator& right) const {
            return this->node != right.node;
        }

        /**
         * returns an iterator on next node
         * @return Iterator on next node
         * @throw out_of_range exception
         */
        Iterator operator++() {
            return next();
        }

        /**
         * returns an iterator on previous node
         * @return Iterator on previous node
         * @throw out_of_range exception
         */
        Iterator operator--() {
            return previous();
        }

        /**
         * returns data of current node
         * @return data of current node
         */
        T& operator*() {
            return this->node->data;
        }

        /**
         * Returns property of current node
         * @return property of current node
         */
        T& operator->() {
            return node->data;
        }
    };

    /**
     * Constant iterator that assures no elements
     * won't be modified
     */
    class ConstIterator : public Iterator {
    public:
        ConstIterator(Node<T>* node) : Iterator(node) {}

        /**
         * Overload * operator to return constant data
         * @return unmodifiable data
         */
        const T& operator*() const {
            return this->node->data;
        }

        /**
         * returns current node
         * @return current node
         */
        const Node<T>* getNode() {
            return Iterator::node;
        }

        /**
         * Returns a ConstIterator on next node
         * @return ConstIterator on next node
         * @throw out_of_range exception
         */
        ConstIterator next() {
            Iterator::node = Iterator::node->next;
            return *this;
        }

        /**
         * Returns a ConstIterator on previous node
         * @return ConstIterator on previous node
         * @throw out_of_range exception
         */
        ConstIterator previous() {
            if (Iterator::node->prev != nullptr)
                Iterator::node = Iterator::node->prev;
            return *this;
        }

        /**
         * Returns a ConstIterator on next node
         * @return ConstIterator on next node
         */
        ConstIterator operator++() {
            return next();
        }

        /**
         * Returns a ConstIterator on previous node
         * @return ConstIterator on previous node
         */
        ConstIterator operator--() {
            return previous();
        }
    };

    /**
     * @brief Basic constructor
     */
    List() : length(0), head(new Node<T>()), tail(new Node<T>()) {
        head->next = tail;
        tail->prev = head;
    }

    /**
     * @brief Constructor with initializer list
     */
    List(std::initializer_list<T> l) {
        std::vector<T> vector = l;
        length = vector.size();

        if (length == 0) {
            List();
            return;
        }
        if (length == 1) {
            Node<T>* newNode = new Node<T>(vector[0]);
            head->next = newNode;
            tail->prev = newNode;
        } else {
            head = new Node<T>();
            Node<T>* cur = head;
            for (T data : vector) {
                cur->next = new Node<T>(data);
                cur->next->prev = cur;
                cur = cur->next;
            }
            tail = new Node<T>();
            tail->prev = cur;
            cur->next = tail;
        }
    }

    /**
     * @brief Copy constructor
     * @param const List& list : list to copy
     */
    List(const List& list) : List() {
        for (Iterator it = list.begin(); it != list.end(); ++it) {
            append(*it);
        }
    }

    /**
     * Destructor, clear the list then the head and tail
     */
    ~List() {
        clear();
        delete(head);
        delete(tail);
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
    void insert(const T& o) {
        Node<T>* newNode = new Node<T>(o);
        if (head->next == tail) {
            head->next = newNode;
            tail->prev = newNode;
            newNode->prev = head;
            newNode->next = tail;
        } else {
            Node<T>* tmp = head->next;
            head->next = newNode;
            newNode->prev = head;
            tmp->prev = newNode;
            newNode->next = tmp;
        }

        length++;
    }

    /**
     * @brief Inserts a new element to the end of the list
     * @param const T& o : reference on element to add
     */
    void append(const T& o) {
        Node<T>* newNode = new Node<T>(o);
        if (head->next == tail) {
            head->next = newNode;
            tail->prev = newNode;
            newNode->prev = head;
            newNode->next = tail;
        } else {
            Node<T>* tmp = tail->prev;
            tail->prev = newNode;
            newNode->next = tail;
            tmp->next = newNode;
            newNode->prev = tmp;
        }

        length++;
    }

    /**
     * @brief Removes element at given index
     * @param const size_t index : index of element to remove
     * @throws out_of_range exception
     */
    void removeAt(const size_t index) {
        if (index < 0 || index >= length)
            throw std::out_of_range("Out of range");
        else if (length == 1) {
            head->next = tail;
            tail->prev = head;
        } else {
            Iterator it = begin();
            for (int i = 0; i < index; ++i) {
                ++it;
            }
            Node<T>* toDelete = it.getNode();

            toDelete->prev->next = toDelete->next;
            toDelete->next->prev = toDelete->prev;
            delete(toDelete);
        }
        length--;
    }

    /**
     * @brief Removes element
     * @param const T& o : element to remove
     */
    void remove(const T& o) {
        removeAt(find(o));
    }

    /**
     * @brief Creates and returns an iterator on the end of the list
     * @return Iterator& iterator on the begining of the list
     */
    ConstIterator& begin() const {
        ConstIterator* it = new ConstIterator(head->next);
        return *it;
    }

    /**
     * @brief Creates and returns an iterator on the end of the list
     * @return Iterator& iterator on the end of the list
     */
    ConstIterator& end() const {
        ConstIterator* it = new ConstIterator(tail);
        return *it;
    }

    /**
     * @brief Finds index of given element in the list
     * @param const T& o : element to find
     */
    int find(const T& o) {
        Iterator it = begin();
        int i = 0;
        while (i < length) {
            if (*it == o) {
                return i;
            }
            ++i;
            ++it;
        }

        return -1;
    }

    /**
     * Clears the list and delete its nodes
     */
    void clear() {
        for (Iterator it = begin(); it != end(); ++it) {
            delete it.getNode();
        }
    }

    /**
     * @brief Override = operator
     * @param const List& l : list to copy
     */
    List& operator=(const List& l) {
        head = l.begin().getNode();
        tail = l.end().getNode();
        length = l.size();
    }

    /**
     * @brief Overrides [] operator
     * @param const size_t i : index in the list
     * @throw out_of_range exception
     */
    T& operator[](const size_t i) {
        if (i < 0 || i >= length)
            throw std::out_of_range("Out of range");
        Iterator it = begin();
        for (int j = 0; j < i; ++j) {
            ++it;
        }
        return *it;
    }

    /**
     * @brief inserts the values of the list into os
     * @param ostream object where the values are inserted
     * @param l the list object with the content to insert
     * @return os parameter
     */
    friend std::ostream& operator<<(std::ostream& os, const List<T>& l) {
        for (Iterator it = l.begin(); it != l.end(); ++it) {
            os << *it << " ";
        }
        return os;
    }
};


#endif //LIST_LIST_H
