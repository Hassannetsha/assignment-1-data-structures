#include <iostream>
using namespace std;

template<typename T>
class Single_Linked_List{
    struct Node {
        T data;
        Node* next;
        Node(const T& newData) : data(newData), next(nullptr) {}
    };
    Node* head;
public:
    Single_Linked_List() : head(nullptr) {}
    void Create(const T arr[], int n) {
        if (n <= 0) return;
        head = new Node(arr[0]);
        Node* last = head;
        for (int i = 1; i < n; ++i) {
            last->next = new Node(arr[i]);
            last = last->next;
        }
    }
    void swap(int index1, int index2) {
        if (index1 == index2) return;
        Node* p = head;
        Node* q = head;
        for (int i = 0; i < index1 && p; ++i) p = p->next;
        for (int i = 0; i < index2 && q; ++i) q = q->next;
        if (!p || !q) return;
        T temp = p->data;
        p->data = q->data;
        q->data = temp;
    }
    bool isItemAtEqual(const T& value, int index) {
        Node* p = head;
        for (int i = 0; i < index && p; ++i) p = p->next;
        return (p && p->data == value);
    }
    bool isExist(const T& value) {
        Node* p = head;
        while (p) {
            if (p->data == value) return true;
            p = p->next;
        }
        return false;
    }
    void replaceAt(const T& value, int index) {
        Node* p = head;
        for (int i = 0; i < index && p; ++i) p = p->next;
        if (p) p->data = value;
    }
    T retrieveAt(int index) {
        Node* p = head;
        for (int i = 0; i < index && p; ++i) p = p->next;
        if (p) return p->data;
        return T();
    }
    void removeAt(int index) {
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* p = head;
        Node* prev = nullptr;
        for (int i = 0; i < index && p; ++i) {
            prev = p;
            p = p->next;
        }
        if (p) {
            prev->next = p->next;
            delete p;
        }
    }
    void removeAtTail() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* p = head;
        Node* prev = nullptr;
        while (p->next) {
            prev = p;
            p = p->next;
        }
        delete p;
        if (prev) prev->next = nullptr;
    }
    void removeAtHead() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void insertAt(const T& value, int index) {
        if (index == 0) {
            Node* newNode = new Node(value);
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* p = head;
        for (int i = 0; i < index - 1 && p; ++i) p = p->next;
        if (p) {
            Node* newNode = new Node(value);
            newNode->next = p->next;
            p->next = newNode;
        }
    }
    void insertAtTail(const T& value) {
        if (!head) { // Empty list
            head = new Node(value);
            return;
        }
        Node* p = head;
        while (p->next) p = p->next;
        p->next = new Node(value);
    }
    void insertAtHead(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    bool isEmpty() {
        return (head == nullptr);
    }
    void Clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    int size() {
        int count = 0;
        Node* p = head;
        while (p) {
            ++count;
            p = p->next;
        }
        return count;
    }
    void Print() {
        Node* p = head;
        while (p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    ~Single_Linked_List() {
        Clear();
    }
};
int main() {
    Single_Linked_List<int> list;
    int arr[] = {1, 2, 3, 4, 5};
    list.Create(arr, 5);
    list.Print();
    list.insertAtHead(0);
    list.Print();
    list.insertAtTail(6);
    list.Print();
    list.insertAt(100, 3);
    list.Print();
    list.removeAtHead();
    list.Print();
    list.removeAtTail();
    list.Print();
}