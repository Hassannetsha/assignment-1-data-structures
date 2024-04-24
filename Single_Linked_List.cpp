#include <iostream>
using namespace std;

template<typename T>
class Single_Linked_List{
//struct Node {
//    T data;
//    struct Node *next;
//};
    struct Node {
        T data;
        Node* next;
        Node(const T& newData) : data(newData), next(nullptr) {}
    };

    Node* head;
//    Single_Linked_List(){
//        first = nullptr;
//    }
public:
    Single_Linked_List() : head(nullptr) {}

//void Create(const T arr[], int n) {
//    struct Node *t, *last;
//    first = new Node;
//    first->data = arr[0];
//    first->next = nullptr;
//    last = first;
//    for (int i = 1; i < n; ++i) {
//        t = new Node;
//        t->data = arr[i];
//        t->next = nullptr;
//        last->next = t;
//        last = t;
//    }
//}

    void Create(const T arr[], int n) {
        if (n <= 0) return; // No elements to create
        head = new Node(arr[0]);
        Node* last = head;
        for (int i = 1; i < n; ++i) {
            last->next = new Node(arr[i]);
            last = last->next;
        }
    }

//void swap(int index1, int index2) {
//    struct Node *p = first;
//    struct Node *t = first;
//    for (int i = 0; i < index1 - 1; ++i) {
//        p = p->next;
//    }
//    for (int i = 0; i < index2; ++i) {
//        t = t->next;
//    }
//    int change = p->data;
//    p->data = t->data;
//    t->data = change;
//}
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

//bool isItemAtEqual(int a, int index) {
//    struct Node *p = first;
//    for (int i = 0; i < index - 1; ++i) {
//        p = p->next;
//    }
//    if (p->data == a)
//        return true;
//    else
//        return false;
//
//}
    bool isItemAtEqual(const T& value, int index) {
        Node* p = head;
        for (int i = 0; i < index && p; ++i) p = p->next;
        return (p && p->data == value);
    }

//bool isExist(int a) {
//    struct Node *p = first;
//    while (p->next != nullptr) {
//        if (p->data == a)
//            return true;
//        else
//            p = p->next;
//    }
//    return false;
//}
    bool isExist(const T& value) {
        Node* p = head;
        while (p) {
            if (p->data == value) return true;
            p = p->next;
        }
        return false;
    }
//
//void replaceAt(int a, int index) {
//    struct Node *p = first;
//    for (int i = 0; i < index - 1; ++i) {
//        p = p->next;
//    }
//    p->data = a;
//}
    void replaceAt(const T& value, int index) {
        Node* p = head;
        for (int i = 0; i < index && p; ++i) p = p->next;
        if (p) p->data = value;
    }

//
//int retrieveAt(int index) {
//    struct Node *p = first;
//    for (int i = 0; i < index - 1; ++i) {
//        p = p->next;
//    }
//    return p->data;
//}
    T retrieveAt(int index) {
        Node* p = head;
        for (int i = 0; i < index && p; ++i) p = p->next;
        if (p) return p->data;
        // Return a default value if index is out of bounds
        return T();
    }

//void removeAt(int index) {
//    struct Node *p = first;
//    struct Node *t = nullptr;
//    for (int i = 0; i < index - 1; ++i) {
//        t = p;
//        p = p->next;
//    }
//    t->next = p->next;
//    delete p;
//
//}
    void removeAt(int index) {
        if (index == 0) { // Special case: remove head
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

//void removeAtTail() {
//    struct Node *p = first;
//    while (p->next != nullptr) {
//        p = p->next;
//    }
//    delete p;
//}

    void removeAtTail() {
        if (!head) return; // Empty list
        if (!head->next) { // Only one node
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

//void removeAtHead() {
//    struct Node *p = first;
//    first  = first->next;
//    delete p;
//}
    void removeAtHead() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

//void insertAt(int a, int index) {
//    struct Node *t, *p = first;
//    t = new Node;
//    t->data = a;
//    for (int i = 0; i < index - 1; ++i) {
//        p = p->next;
//    }
//    t->next = p->next;
//    p->next = t;
//}
    void insertAt(const T& value, int index) {
        if (index == 0) { // Special case: insert at head
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

//void insertAtTail(int a) {
//    struct Node *t, *p = first;
//    t = new Node;
//    t->data = a;
//    t->next = nullptr;
//    while (true) {
//        if (p->next == nullptr) {
//            p->next = t;
//            break;
//        } else {
//            p = p->next;
//        }
//    }
//}
    void insertAtTail(const T& value) {
        if (!head) { // Empty list
            head = new Node(value);
            return;
        }
        Node* p = head;
        while (p->next) p = p->next;
        p->next = new Node(value);
    }

//void insertAtHead(int a) {
//    struct Node *t;
//    t = new Node;
//    t->data = a;
//    t->next = first;
//    first = t;
//}

    void insertAtHead(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

//bool isEmpty(struct Node *p) {
//    if (p->next != nullptr)
//        return false;
//    else
//        return true;
//}
    bool isEmpty() {
        return (head == nullptr);
    }


//void Clear(struct Node *p) {
//    p = nullptr;
//}
    void Clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
//
//int linkedListSize(struct Node *p) {
//    int count = 0;
//    while (p->next != nullptr) {
//        count++;
//        p = p->next;
//    }
//    return count;
//}
    int size() {
        int count = 0;
        Node* p = head;
        while (p) {
            ++count;
            p = p->next;
        }
        return count;
    }

//void Print(struct Node *p) {
//    while (p->next != nullptr) {
//        cout << p->data;
//        p = p->next;
//    }

    void Print() {
        Node* p = head;
        while (p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }



//    ~Single_Linked_List()
//    {
//        Node *s;
//
//        while(first!= nullptr)
//        {
//            s = first;
//            first = first->next;
//            delete s;
//        }
//
//    }
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









