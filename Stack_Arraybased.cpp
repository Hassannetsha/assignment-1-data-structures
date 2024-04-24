#include "iostream"
using namespace std;





class Stack_Arraybased{
//private:
//    int size;
//    int top;
//    int *s;
private:
    int capacity;
    int top_index;
    int *stack_array;

public:
//    Stack_Arraybased(int size)
//    {
//        this->size = size;
//        s = new int[size];
//    }
    Stack_Arraybased(int capacity) : capacity(capacity), top_index(-1) {
        stack_array = new int[capacity];
    }
//void push( int a) {
//    if (this->top == this->size - 1) {
//        cout << "stack overflow";
//    } else {
//        this->top++;
//        this->s[this->top] = a;
//    }
//
//
//}
    void push(int value) {
        if (!isFull()) {
            stack_array[++top_index] = value;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

//int pop() {
//    int x = -1;
//    if (this->top == -1) {
//        cout << "stack underflow";
//    } else {
//        x = this->s[this->top];
//        this->top--;
//    }
//    return x;
//}
    int pop() {
        if (!isEmpty()) {
            return stack_array[top_index--];
        } else {
            cout << "Stack Underflow" << endl;
            return -1;
        }
    }


//int Top() {
//    if (this->top == -1) {
//        return -1;
//    } else {
//        return this->s[this->top];
//    }
//}
    int top() const {
        if (!isEmpty()) {
            return stack_array[top_index];
        } else {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

//bool isEmpty() {
//    if (this->top == -1) {
//        return true;
//    } else
//        return false;
//}
    bool isEmpty() const {
        return top_index == -1;
    }

//int Stack_Size() {
//    return this->size;
//}

//void clear() {
//    this->top = -1;
//}
//
//void print() {
//    for (int i = 0; i < this->size; ++i) {
//        cout << this->s[i];
//    }
//}
//    ~Stack_Arraybased(){
//    delete[] s;
//
//}
    bool isFull() const {
        return top_index == capacity - 1;
    }

    int size() const {
        return capacity;
    }

    void clear() {
        top_index = -1;
    }

    void display() const {
        if (!isEmpty()) {
            cout << "Stack elements: ";
            for (int i = 0; i <= top_index; ++i) {
                cout << stack_array[i] << " ";
            }
            cout << endl;
        } else {
            cout << "Stack is empty" << endl;
        }
    }

    ~Stack_Arraybased() {
        delete[] stack_array;
    }
};
int main() {
    Stack_Arraybased stack(5);

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.display();
    cout << stack.top() << endl;
    cout <<  stack.pop() << endl;
    stack.display();
    stack.clear();
    stack.display();
}