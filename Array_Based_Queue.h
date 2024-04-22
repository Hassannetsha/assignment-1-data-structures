#ifndef ASSIGNMENT_DATA_STRUCTURES_ARRAY_BASED_QUEUE_H
#define ASSIGNMENT_DATA_STRUCTURES_ARRAY_BASED_QUEUE_H

#include <iostream>
#include <cmath>

using namespace std;

template<typename T>
class Array_Based_Queue {
    T *queue;
    int rear;
    int size{};
    int front;
    int ctn{};
public:
    Array_Based_Queue() {
        queue = nullptr;
        rear = -1;
        size = 0;
        ctn = 0;
        front = -1;
    }

    explicit Array_Based_Queue(const int &size) {
        queue = new T[size];
        this->size = size;
        rear = -1;
        front = -1;
        ctn = 0;
    }

    bool isEmpty() {
        return rear == front;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void enqueue(const T &data) {
        if (rear == (-1) && size == 0) {
            size = 10;
            queue = new T[size];
            rear = (rear + 1) % size;
            queue[rear] = data;
        } else if (isFull() && size != 0) {
            T *newQueue = new T[size * 2], *deleteOld;
            for (int i = 0; i <= rear; ++i) {
                newQueue[i] = queue[i];
            }
            deleteOld = queue;
            delete[] deleteOld;
            queue = newQueue;
            size = size * 2;
            rear = (rear + 1) % size;
            queue[rear] = data;
        } else {
            if (front == -1&&ctn!=0) {
                front = 0;
            }
            rear = (rear + 1) % size;
            queue[rear] = data;
            ctn++;
        }
    }

    T dequeue() {
        T default_value;
        if (!isEmpty()) {
            int number = front;
            front = (front+1)%size;
            return queue[number];
        } else {
            cout << "can'T delete an empty queue\n";
            cout << "trash element ";
            return T();
        }
    }

    T first() {
        if (!isEmpty()) {
            if(ctn==0){
                return queue[rear];
            }
            else{ return queue[front]; }
        }
        else {
            cout << "Queue is empty\n";
            cout << "trash element ";
            return T();
        }
    }

    T back() {
        if (!isEmpty()) { return queue[rear]; }
        else {
            cout << "Queue is empty\n";
            cout << "trash element ";
            return T();
        }
    }

    int queueSize() {
        return rear + 1;
    }

    void clear() {
        if (!isEmpty()) {
            rear = -1;
            front = -1;
            delete[] queue;
        } else {
            cout << "It is already empty\n";
        }
    }

    void print() {
        if (!isEmpty()) {
            if(ctn!=1){
                int i = (front);
                while (i != rear) {
                    if (std::is_same<T, bool>::value) {
                        queue[i]==0 ? cout << "True"<< ' ':cout << "False"<< ' ';
                    }
                    else{ cout << queue[i] << ' '; }
                    i = (i + 1) % size;
                }
            }
            if (std::is_same<T, bool>::value) {
                queue[rear]==0 ? cout << "True"<< ' ':cout << "False"<< ' ';
            }
            else{ cout << queue[rear] << ' '; }
            cout << '\n';
        } else {
            cout << "queue is empty\n";

        }
    }

    ~Array_Based_Queue() {
        if (!isEmpty()) { delete[] queue; }
    }
};

#endif //ASSIGNMENT_DATA_STRUCTURES_ARRAY_BASED_QUEUE_H
