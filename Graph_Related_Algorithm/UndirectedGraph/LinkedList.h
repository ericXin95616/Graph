//
// Created by xinbochao on 18-7-12.
//

#ifndef GRAPH_LINKEDLIST_H
#define GRAPH_LINKEDLIST_H

#include <string>
#include <exception>

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
        LinkedListIterator(const Node<T>* head, const Node<T>* current);

        T& operator*();

        LinkedListIterator<T>& operator++(); // pre
        LinkedListIterator<T> operator++(int); // post

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
LinkedListIterator<T>::LinkedListIterator(const Node<T> *head): head(head), currentNode(head)
{}

template <typename T>
LinkedListIterator<T>::LinkedListIterator(const Node<T> *head, const Node<T>* current): head(head), currentNode(current)
{}

template <typename T>
T& LinkedListIterator<T>::operator*() {
    if(currentNode != nullptr)
        return currentNode->data;
    throw std::out_of_range("The iterator you try to dereference is out of range.");
}

template <typename T>
LinkedListIterator<T>& LinkedListIterator<T>::operator++() {
    if(currentNode != nullptr) {
        currentNode = currentNode->next;
        return *this;
    }
    throw std::out_of_range("The iterator you try to move is out of range.");
}

template <typename T>
LinkedListIterator<T> LinkedListIterator<T>::operator++(int) {
    if(currentNode != nullptr) {
        LinkedListIterator<T> temp(head, currentNode);
        currentNode = currentNode->next;
        return temp;
    }
    throw std::out_of_range("The iterator you try to move is out of range.");
}

template <typename T>
bool LinkedListIterator<T>::operator bool() const {
    return currentNode != nullptr;
}

template <typename T>
bool LinkedListIterator<T>::operator!() const {
    return currentNode == nullptr; // will !(*this) cause bug?
}

template <typename T>
bool LinkedListIterator<T>::operator==(const LinkedListIterator<T> &rightItr) {
    return compatible(rightItr) && (currentNode == rightItr.currentNode);
}

template <typename T>
bool LinkedListIterator<T>::operator!=(const LinkedListIterator<T> &rightItr) {
    return !(*this == rightItr);
}

template <typename T>
bool LinkedListIterator<T>::compatible(const LinkedListIterator<T> &rightItr) {
    return head == rightItr->head;
}



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
