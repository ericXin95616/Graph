//
// Created by xinbochao on 18-7-12.
//

#ifndef GRAPH_LINKEDLIST_H
#define GRAPH_LINKEDLIST_H

#include <string>
#include <exception>
#include <sstream>

using std::string;
using std::stringstream;

// we just implement a single linked list
template <typename T>
class Node{
public:
    T data;
    Node<T> *next;

    explicit Node(const T& _data, Node* nextNode = nullptr) {
        data = _data;
        next = nextNode;
    }
};

template <typename T>
class LinkedListIterator{
public:
    explicit LinkedListIterator( Node<T>* head);
    LinkedListIterator( Node<T>* head, Node<T>* current);

    T& operator*();

    LinkedListIterator<T>& operator++(); // pre
    LinkedListIterator<T> operator++(int); // post

    explicit operator bool() const; // true if iterator is in bound
    bool operator!() const; // true if not in bound

    bool operator==(const LinkedListIterator<T>& rightItr);
    bool operator!=(const LinkedListIterator<T>& rightItr);

private:
    bool compatible(const LinkedListIterator<T>& rightItr); // judge if two iterators refer to the same LinkedList
    Node<T>* head;
    Node<T>* currentNode;
};

template <typename T>
LinkedListIterator<T>::LinkedListIterator(Node<T> *head): head(head), currentNode(head)
{}

template <typename T>
LinkedListIterator<T>::LinkedListIterator(Node<T> *head, Node<T>* current): head(head), currentNode(current)
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
LinkedListIterator<T>::operator bool() const {
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
    return head == rightItr.head;
}




template <typename T>
class LinkedList{
    friend  LinkedListIterator<T>;
public:
    LinkedList() { head = nullptr; }
    bool isempty() const;

    void push(const T& data);
    T pop();

    LinkedListIterator<T> _begin();
    LinkedListIterator<T> _end();

    string toString() const;
    ~LinkedList();

private:
    Node<T> *head;
};

template <typename T>
bool LinkedList<T>::isempty() const {
    return head == nullptr;
}

template <typename T>
void LinkedList<T>::push(const T &data) {
    auto *newNode = new Node<T>(data, head);
    head = newNode;
}

template <typename T>
T LinkedList<T>::pop() {
    Node<T> *temp = head;
    head = head->next;
    T tempVal = temp->data;
    delete temp;
    return tempVal;
}

template <typename T>
LinkedListIterator<T> LinkedList<T>::_begin() {
    return LinkedListIterator<T>(head);
}

template <typename T>
LinkedListIterator<T> LinkedList<T>::_end() {
    return LinkedListIterator<T>(head, nullptr);
}

template <typename T>
string LinkedList<T>::toString() const {
    string output, tempData;
    stringstream ss;
    Node<T> *temp = head;
    while(temp != nullptr) {
        ss << temp->data;
        ss >> tempData;
        output = output + tempData + "->";
        temp = temp->next;
        ss.clear();
    }
    output += "NULL";
    return output;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T> *temp;
    while(head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

#endif //GRAPH_LINKEDLIST_H










