#include "iostream"
using namespace std;

class Stack_linklistbased{
//private:
//    struct Node{
//        int data;
//        struct Node *next;
//    };
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
//    struct Node *top = nullptr;
    Node* top;

//public:
//    void Push(int x){
//        struct Node *t;
//        t = new Node;
//        if (t == nullptr)
//        {
//            cout << "Stack is full";
//        }
//        else{
//            t->data = x;
//            t->next = top;
//            top = t;
//        }
//
//    }
public:
    Stack_linklistbased() : top(nullptr) {}

    void push(int x) {
        Node* newNode = new Node(x);
        if (newNode == nullptr) {
            cout << "Stack overflow!" << std::endl;
        } else {
            newNode->next = top;
            top = newNode;
        }
    }
//    int Pop()
//    {
//        struct Node *t;
//        int x = -1;
//        if(top == nullptr){
//            cout << "Stack is empty";
//        }
//        else{
//            t = top;
//            top = top->next;
//            x = t->data;
//            delete t;
//        }
//        return x;
//    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        Node* temp = top;
        int poppedValue = temp->data;
        top = top->next;
        delete temp;
        return poppedValue;
    }
//    void Print(){
//        struct Node *t;
//        t = top;
//        while (t != nullptr)
//        {
//            cout << t->data;
//            t = t->next;
//        }
//    }
    void print() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* current = top;
        cout << "Stack elements: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
//    int Top(){
//        if (top != nullptr)
//        {
//            return top->data;
//        }
//        return -1;
//    }
    int Top() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }

//    bool isEmpty(){
//        return top == nullptr;
//    };
    bool isEmpty() {
        return top == nullptr;
    }


//    int Stack_size()
//    {
//        int n = 0;
//        struct Node *t;
//        t = top;
//        while (t != nullptr){
//            n++;
//            t = t->next;
//        }
//        return n;
//
//    }
    int size() {
        int count = 0;
        Node* current = top;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

//    void clear(){
//        top = nullptr;
//    }
    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }
//    ~Stack_linklistbased()
//    {
//        Node *s;
//
//        while(top!= nullptr)
//        {
//            s = top;
//            top = top->next;
//            delete s;
//        }
//
//    }
    ~Stack_linklistbased() {
        clear();
    }


};

int main() {
    Stack_linklistbased stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout <<  stack.size() << endl;
    stack.print();
    while (!stack.isEmpty()) {
        cout << stack.pop() << " ";
    }
    cout << stack.size() << std::endl;

}