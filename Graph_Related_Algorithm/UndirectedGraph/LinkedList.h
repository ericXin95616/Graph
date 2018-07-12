//
// Created by xinbochao on 18-7-12.
//

#ifndef GRAPH_LINKEDLIST_H
#define GRAPH_LINKEDLIST_H

#include <string>

using std::string;

// we just implement a single linked list
template <typename T>
class Node{
    public:
        T data;
        Node<T> *next;

        Node() {
            next = nullptr;
        }
};

template <typename T>
class LinkedListIterator{
    public:
        LinkedListIterator(const Node<T>* head);

        T& operator*();

        LinkedListIterator<T>& operator++(); // pre
        LinkedListIterator<T>& operator++(int); // post

        operator bool() const; // true if iterator is in bound
        bool operator!() const; // true if not in bound

        bool operator==(const LinkedListIterator<T>& rightItr);
        bool operator!=(const LinkedListIterator<T>& rightItr);

    private:
        bool compatible(const LinkedListIterator<T>& rightItr); // judge if two iterators refer to the same LinkedList
        Node<T>* head;
        Node<T>* currentNode;
};

template <typename T>
class LinkedList{
    public:
        LinkedList() { head = nullptr; }
        bool isempty() const;

        void push_back(const T& data);
        T pop_back();

        LinkedListIterator<T>& _begin();
        LinkedListIterator<T>& _end();

        string toString() const;
        ~LinkedList();

    private:
        Node<T> *head;
};
#endif //GRAPH_LINKEDLIST_H
