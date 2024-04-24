#ifndef ASSIGNMENT_DATA_STRUCTURES_LINKEDQUEUE_H
#define ASSIGNMENT_DATA_STRUCTURES_LINKEDQUEUE_H

#include <iostream>
#include <cmath>

using namespace std;

template<typename T>
class linkedQueue {
    struct node {
        T item;
        node *next_item;
    };
    node *front;
    node *rear;
    int index{};
public:
    linkedQueue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return index == 0;
    }

    void enqueue(const T &x) {
        node *temp = new node();
        temp->item = x;
        if (isEmpty()) {
            front = rear = temp;
        } else {
            rear->next_item = temp;
            temp->next_item = nullptr;
            rear = temp;
        }
        index++;
    }

    T dequeue() {
        T number;
        if (!isEmpty()) {
            node *temp = front;
            front = front->next_item;
            temp->next_item = nullptr;
            number = temp->item;
            delete temp;
            index--;
            return number;
        } else {
            cout << "can'T delete an empty queue\n";
            cout << "trash element ";
            return T();
        }
    }

    T first() {
        if (!isEmpty()) { return front->item; }
        else {
            cout << "Queue is empty\n";
            cout << "trash element ";
            return T();
        }
    }

    T back() {
        if (!isEmpty()) { return rear->item; }
        else {
            cout << "Queue is empty\n";
            cout << "trash element ";
            return T();
        }
    }

    int queueSize() {
        return index + 1;
    }

    void clear() {
        if (!isEmpty()) {
            while (front == nullptr) {
                node *temp = front;
                front = front->next_item;
                delete temp;
            }
            rear = nullptr;
            index = 0;
        }
        else {
            cout << "It is already empty\n";
        }
    }

    void print() {
        if (!isEmpty()) {
            node *items = front;
            while (items != nullptr) {
                cout << items->item << " ";
                items = items->next_item;
            }
            cout << '\n';
        } else {
            cout << "There is no elements\n";
        }
    }

    ~linkedQueue() {
        if (!isEmpty()) {
            while (front != nullptr) {
                node *temp = front;
                front = front->next_item;
                delete temp;
            }
            rear = nullptr;
        }
    }
};

#endif