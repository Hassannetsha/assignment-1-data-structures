#include <iostream>

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
        size = 5;
        queue = new T[size];
        rear = -1;
        ctn = 0;
        front = 0;
    }

    explicit Array_Based_Queue(const int &size) {
        queue = new T[size];
        this->size = size;
        rear = -1;
        front = 0;
        ctn = 0;
    }

    bool isEmpty() {
        return ctn==0;
    }

    bool isFull() {
        return ctn==size;
    }

    void enqueue(const T &data) {
            if (isFull()) {
            cout<<"Deque is Expanding ";
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
            ctn++;
        } else {
            rear = (rear + 1) % size;
            queue[rear] = data;
            ctn++;
        }
    }

    T dequeue() {
        if (!isEmpty()) {
            int number = front;
            front = (front+1)%size;
            ctn--;
            return queue[number];
        } else {
            cout << "can'T delete an empty queue\n";
            cout << "trash element ";
            return T();
        }
    }
    T first() {
        if (!isEmpty()) {
            return queue[front];
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
        return ctn;
    }
    void clear() {
        if (!isEmpty()) {
            rear = -1;
            front = -1;
            ctn = 0;
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
int main(){
    Array_Based_Queue<int> arr;
    arr.enqueue(1);
    arr.enqueue(2);
    cout<<arr.first()<<' ';
    cout<<arr.back()<<'\n';
    cout<<"print elements\n";
    arr.print();
    arr.enqueue(3);
    arr.enqueue(4);
    arr.enqueue(5);
    arr.enqueue(6);
    arr.enqueue(7);
    arr.enqueue(8);
    cout<<"print elements\n";
    arr.print();
    cout<<"queue size "<<arr.queueSize()<<'\n';
    cout<<"first dequeue "<<arr.dequeue()<<'\n';
    cout<<"second dequeue "<<arr.dequeue()<<'\n';
    cout<<"third dequeue "<<arr.dequeue()<<'\n';
    cout<<"fourth dequeue "<<arr.dequeue()<<'\n';
    cout<<"fifth dequeue "<<arr.dequeue()<<'\n';
    arr.clear();
    cout<<"sixth dequeue "<<arr.dequeue()<<'\n';
    cout<<"queue size "<<arr.queueSize()<<'\n';
    cout<<"print elements\n";
    arr.print();
}