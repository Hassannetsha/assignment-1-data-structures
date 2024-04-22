#ifndef ASSIGNMENT_DATA_STRUCTURES_ARRAY_BASED_QUEUE_H
#define ASSIGNMENT_DATA_STRUCTURES_ARRAY_BASED_QUEUE_H
#include <iostream>
#include <cmath>
using namespace std;
template<typename T>
class Array_Based_Queue {
    T* queue;
    int index;
    int size;
    int front;
public:
    Array_Based_Queue() {
        queue = nullptr;
        index = -1;
        size = 0;
        front = 0;
    }
    Array_Based_Queue(const int& size) {
        queue = new T[size];
        this->size = size;
        index = -1;
        front = 0;
    }
    bool isEmpty() {
        return index <= 0 ;
    }
    bool isFull(){
        return index+1>=size  ;
    }
    void enqueue(const T& data) {
        if(index == (-1)&&size==0){
            size = 10;
            queue = new T[size];
            queue[++index] = data;
        }
        else if (isFull()){
            T *newQueue = new T[size * 2], *deleteOld;
            for (int i = 0; i <= index; ++i) {
                newQueue[i] = queue[i];
            }
            deleteOld = queue;
            delete[] deleteOld;
            queue = newQueue;
            queue[++index] = data;
            size = size * 2;
        }
        else{
            queue[++index] = data;
        }
    }
    T dequeue() {
        if (!isEmpty()) {
            return queue[front++];
        }
        else {
            cout << "can'T delete an empty queue\n";
            cout<<"trash element ";
            return INFINITY;
        }
    }
    T first() {
        return queue[front];
    }
    T back() {
        return queue[index];
    }
    int queueSize() {
        return index+1;
    }
    void clear() {
        if (!isEmpty()) {
            index = -1;
            delete[] queue;
        }
        else{
            cout<<"It is already empty\n";
        }
    }
    void print(){
        if(!isEmpty()){
            for (int i = 0; i <= index; ++i) {
                cout << queue[i] << ' ';
            }
            cout << '\n';
        }
        else{
            cout<<"queue is empty\n";

        }
    }
    ~Array_Based_Queue()
    {
        if(!isEmpty()){ delete[] queue; }
    }
};
#endif //ASSIGNMENT_DATA_STRUCTURES_ARRAY_BASED_QUEUE_H
