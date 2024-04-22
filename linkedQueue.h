#ifndef ASSIGNMENT_DATA_STRUCTURES_LINKEDQUEUE_H
#define ASSIGNMENT_DATA_STRUCTURES_LINKEDQUEUE_H
#include <iostream>
#include <cmath>
using namespace std;
template<typename T>
class linkedQueue {
    struct node {
        T item;
        node* next_item;
    };
    node* front;
    node* rear;
    int index{};
public:
    linkedQueue() {
        front = nullptr;
        rear = nullptr;
    }
    bool isEmpty() {
        return index == 0;
    }
    void enqueue(const T& x) {
        node* temp = new node();
        temp->item = x;
        if (isEmpty()) {
            front = rear = temp;
        }
        else {
            rear->next_item = temp;
            temp->next_item = nullptr;
            rear = temp;
        }
        index++;
    }
    T dequeue() {
        T number;
        if (!isEmpty()) {
            node* temp = front;
            front = front->next_item;
            temp->next_item = nullptr;
            number = temp->item;
            delete temp;
            index--;
            return number;
        }
        else {
            cout << "can'T delete an empty queue\n";
            return INFINITY;
        }
    }
    T first() {
        return front->item;
    }
    T back() {
        return rear->item;
    }
    int queueSize() {
        return index;
    }
    void clear() {
        if (!isEmpty()) {
            while (front == nullptr) {
                node* temp = front;
                front = front->next_item;
                delete temp;
            }
            rear = nullptr;
            index = 0;
        }
    }
    void print(){
        if(!isEmpty()){
            node *items = front;
            while (items != nullptr) {
                cout << items->item << " ";
                items = items->next_item;
            }
            cout << '\n';
        }
        else{
            cout<<"There is no elements\n";
        }
    }
    ~linkedQueue()
    {
        if (!isEmpty()) {
            while (front != nullptr) {
                node* temp = front;
                front = front->next_item;
                delete temp;
            }
            rear = nullptr;
        }
    }
};

#endif //ASSIGNMENT_DATA_STRUCTURES_LINKEDQUEUE_H
