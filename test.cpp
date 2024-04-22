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
    Array_Based_Queue<bool> queue(4);
    queue.enqueue(false);
    queue.enqueue(1);
    queue.enqueue(0);
    queue.enqueue(1);
    queue.enqueue(0);
    queue.print();
//    cout << "queue Size " << queue.queueSize() << '\n';
//    cout << "last element" << queue.back() << '\n';
    queue.clear();
    cout << "dequeue " << queue.dequeue() << '\n';
//    cout << "first element " << queue.first() << '\n';
//    cout << "first element" << queue.first() << '\n';
//    queue.print();
//    cout << "dequeue " << queue.dequeue() << '\n';
//    queue.print();
//    queue.enqueue(3);//[3,2,3,4]
//    queue.print();
//    cout << "dequeue " << queue.dequeue() << '\n';
//    cout << "dequeue " << queue.dequeue() << '\n';
}