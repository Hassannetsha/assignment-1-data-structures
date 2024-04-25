#include<bits/stdc++.h>
using namespace std;
template<typename T>
class CircularLinkedList {
private:
    struct Node {
        T info;
        Node* next;
    };
    Node* head;
    Node* rear;
    int size{};
public:
    CircularLinkedList(){
        head = nullptr;
    }
    ~CircularLinkedList(){
        int i = 0;
        while (head != nullptr && i != size){
            i++;
            Node* p = head;
            head = head -> next;
            p -> next = nullptr;
            delete p;
        }
    }
    bool isempty(){
        return (size == 0);
    }
    void insertAtHead(T data){
        Node* p = new Node;
        p -> info = data;
        p -> next = head;
        if (head == nullptr){
            head = p;
        } else{
            Node* q = head;
            while (q != nullptr && p -> next != nullptr && q -> next != head)
                q = q ->next;
            if (q != nullptr) {
                q->next = p;
            }
            head = p;

        }
        size++;
    }
    void insertAtTail(T data) {
        Node *p = new Node;
        p->info = data;
        p->next = head;
        if (isempty()) {
            head = p;
            head->next = head;
            rear = head;
        }
        else {
            Node *q = head;
            while (q->next != nullptr && q->next != head)
                q = q->next;
            q->next = p;
            rear = p;
        }

        size++;
    }
    void insertAt(T data , int index){
        if(index < 0 || index > size){
            cout<<"index out of range";
            exit(0);
        }
        if (index == 0){
            insertAtHead(data);
        } else if (index == size-1){
            insertAtTail(data);
        } else {
            Node *newnode = new Node;
            newnode->info = data;
            newnode->next = head;
            Node *priv = head;
            while (index > 1) {
                priv = priv->next;
                index--;
            }
            newnode->next = priv->next;
            priv->next = newnode;
            size++;
        }

    }
    void replaceAt(T data , int index){
        Node* p = head;
        if(index < 0 || index > size){
            cout<<"index out of range";
            exit(0);
        }
        while (index > 1){
            p = p -> next;
            index--;
        }
        p ->info = data;
    }
    T retrieveAt(int index){
        Node* p = head;
        if(index < 0 || index > size){
            cout<<"index out of range";
            exit(0);
        }
        if (isempty()){
            cout<<"list is empty";
            exit(0);
        }
        while (index > 1){
            p = p ->next;
            index--;
        }
        return (p->next->info);
    }
    void removeAtHead (){

        if (isempty()){
            cout<<"list is empty";
            exit(0);
        }
        else if(head -> next == head){
            delete head;
            head = nullptr;
        }
        else{
            Node* p = head , *q = head;
            while (q -> next != nullptr && q -> next != head){
                q = q->next;

            }
            head = head ->next;
            q ->next = head;
            delete p;
        }
        size--;
    }
    void clear(){
        if (isempty()){
            cout<<"list is empty";
            exit(0);
        } else {
            Node *p = head;
            while (p -> next != nullptr && p->next != head) {
                Node* q = p;
                p = p->next;
                delete q;
            }
            delete p;
            head = nullptr;
        }
        size = 0;
    }
    void removeAtTail() {
        if (isempty()) {
            cout << "list is empty";
        }
        else if (head->next == head) {
            delete head;
            head = nullptr;
            rear = head;
        }
        else {
            Node *p = head, *q;
            while (p->next != head) {
                q = p;
                p = p->next;

            }
            delete p;
            q->next = head;
            rear = q;
        }
        size--;

    }
    void removeAt (int index) {
        if(index < 0 || index > size){
            cout<<"index out of range";
            exit(0);
        }
        if (isempty()) {
            cout << "List is empty";
        } else {
            Node *p = head;
            if (index == 0) {
                if (head->next == head) {
                    delete head;
                    head = nullptr;
                } else {
                    Node *q = head;
                    while (q->next != head) {
                        q = q->next;
                    }
                    head = head->next;
                    q->next = head;
                    delete p;
                }
            }
            else {
                for (int i = 1; i < index; ++i) {
                    p = p->next;
                    if (p == head) {
                        cout << "Index out of range";
                        exit(0);
                    }
                }
                Node* temp = p->next;
                p->next = temp->next;
                delete temp;
            }
        }
        size--;
    }
    bool isExist (T data){
        Node* p = head;
        if (isempty()){
            return false;
        }
        while (p ->next != head || size == 1){
            if (p->next->info == data){
                return true;
            }
            else {
                p = p ->next;
            }
        }
        return false;
    }
    bool isItemAtEqual (T data , int index) {
        Node *p = head;
        if(index < 0 || index > size){
            cout<<"index out of range";
            exit(0);
        }
        if (isempty()){
            return false;
        }
        else {
            while (index > 1) {
                p = p->next;
                index--;
            }
            if (p->info == data)
                return true;
            else
                return false;
        }
    }
    int linkedListSize(){
        return size;
    }
    void swap(int x, int y) {
        if (x < 0 || y < 0 || x >= size || y >= size) {
            cout << "Index out of range";
        } else if (isempty()) {
            cout << "List is empty";
        } else if (x > y) {
            cout << "please enter the first num smaller than second num ";
        } else if (x == y) {
            return;
        } else {
            /*
             * tx   ty
             *      qx        qy  // qx -> next = qy -> next ; qy -> next = qx;
             *      // tx -> next = qy; ty ->next = qy -> next; // wra b3d
             *      // qx -> next = qy -> next ; qy -> next = qx -> next;
             *      // tx -> next = qy; ty ->next = qx; // m4 wra b3d and edit
             * qx   qy
             * 0    1    2     3     4
             * */
            Node *qx = head, *tx = nullptr;
            for (int i = 0; i < x && i < size; i++) {
                tx = qx;
                qx = qx->next;
            }
            Node *qy = head, *ty = nullptr;
            for (int i = 0; i < y && i < size; i++) {
                ty = qy;
                qy = qy->next;
            }
            if (y == x + 1) {
                qx->next = qy->next;

                if (x != 0)
                    tx->next = qy;
                ty->next = qy->next;
                qy->next = qx;
            } else {
                Node *copy = qx->next;
                if (x != 0 || y != size - 1)
                    qx->next = qy->next;
                else {
                    qx->next = qy;
                }
                qy->next = copy;/* 0 1 2 3 4 */
                if (x != 0)
                    tx->next = qy;
                ty->next = qx;
            }
            if (y == size - 1)
                rear = qx;
            if (x == 0) {
                head = qy;
                rear->next = head;
            }
        }
    }
    void print(){
        Node* p = head;
        if (isempty() || size == 0){
            cout<<"list is empty";
            exit(0);
        }
        while ( p != nullptr && p ->next != head){
            cout<<"\n" << p->info << " " << "\n";
            p = p->next;
        }
        if (p != nullptr)
            cout <<"\n" << p->info;
        cout<<"\n";


    }


};
int main(){

    CircularLinkedList<int> c;
    c.insertAt(1,0);
    c.insertAt(2,1);
    c.insertAt(3,0);
    c.print();
    cout<<"_________________________________"<<"\n";
    c.insertAtTail(4);
    c.print();
    cout<<boolalpha<<c.isempty()<<"\n";
    cout<<boolalpha<<c.isExist(4)<<"\n";
    c.removeAtHead();
    c.print();
    cout<<"_________________________________";
    c.insertAtHead(0);
    c.print();
    cout<<"_________________________________"<<"\n";
    c.clear();
    cout<<boolalpha<<c.isempty()<<"\n";
    cout<<c.isItemAtEqual(1,0)<<"\n" ;
    c.insertAt(1,0);
    cout<<boolalpha<<c.isItemAtEqual(1,0)<<"\n";
    cout<<c.linkedListSize()<<"\n";
    c.insertAt(2,1);
    c.insertAtTail(3);
    c.replaceAt(3,0);
    c.removeAtTail();
    c.removeAt(0);
    c.print();
    cout<<"_________________________________"<<"\n";
    cout<<c.retrieveAt(1);
}