#include <iostream>
//#include "linkedQueue.h"
#include "Array_Based_Queue.h"

using namespace std;

int main() {
//    linkedQueue<int> que;
//    que.enqueue(1);
//    que.enqueue(2);
//    que.enqueue(3);
//    que.enqueue(4);
    Array_Based_Queue<int> queue(2);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.print();
    cout << "queue Size " << queue.queueSize() << '\n';
    cout << "first element" << queue.first() << '\n';
    cout << "last element" << queue.back() << '\n';
    queue.clear();
    queue.print();
    cout << "dequeue " << queue.dequeue() << '\n';
    cout << "dequeue " << queue.dequeue() << '\n';
    cout << "dequeue " << queue.dequeue() << '\n';
    cout << "dequeue " << queue.dequeue() << '\n';
}