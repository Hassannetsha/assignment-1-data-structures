#include <iostream>
using namespace std;

class DoubleLinkedList {
private:
    struct Node {
        int item;
        Node* prev;
        Node* next;
    };
    Node* head;
    Node* tail;
    int size;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void insertAtHead(int element)
    {
        Node* newNode = new Node;
        newNode->item = element;
        if (size == 0)
        {
            head = tail = newNode;
            newNode->next = newNode->prev = nullptr;
        }
        else
        {
            newNode->next = head;
            newNode->prev = nullptr;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void insertAtTail(int element)
    {
        Node* newNode = new Node;
        newNode->item = element;
        if (size == 0)
        {
            head = tail = newNode;
            newNode->next = newNode->prev = nullptr;
        }
        else
        {
            newNode->next = nullptr;
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void insertAt(int element, int index)
    {
        if (index < 0 || index > size)
            cout<<"Out off range!!";
        else
        {
            if (index == 0)
            {
                insertAtHead(element);
            }
            else if (index == size)
            {
                insertAtTail(element);
            }
            else
            {
                Node* newNode = new Node;
                newNode->item = element;
                Node* current = head;
                for (int i = 1; i < index; i++)
                {
                    current = current->next;
                }
                newNode->next = current->next;
                newNode->prev = current;
                current->next->prev = newNode;
                current->next = newNode;
                size++;
            }
        }
    }

    void removeAtHead()
    {
        if (size == 0)
        {
            cout<<"Can't remove from an empty list!!";
        }
        else if (size == 1)
        {
            head = tail = nullptr;
            size--;
        }
        else
        {
            Node* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
            size--;
        }
    }

    void removeAtTail()
    {
        if (size == 0)
        {
            cout<<"Can't remove from an empty list!!";
        }
        else if (size == 1)
        {
            head = tail = nullptr;
            size--;
        }
        else
        {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
            size--;
        }
    }

    void removeAt(int index)
    {
        if (index < 0 || index >= size)
            cout<<"Out off range!!";
        else
        {
            if (index == 0)
            {
                removeAtHead();
            }
            else if (index == size - 1)
            {
                removeAtTail();
            }
            else
            {
                Node* current = head;
                for (int i = 0; i < index; i++)
                {
                    current = current->next;
                }
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                size--;
            }
        }
    }

    int retrieveAt(int index)
    {
        if (index < 0 || index >= size)
        {
            cout<<"Out off range!!";
            return 0;
        }
        else
        {
            Node* current = head;
            for (int i = 0; i < index; ++i)
            {
                current = current->next;
            }
            return current->item;
        }
    }

    void replaceAt(int newElement, int index)
    {
        if (index < 0 || index >= size)
            cout<<"Out off range!!";
        else
        {
            Node* current = head;
            for (int i = 0; i < index; ++i)
            {
                current = current->next;
            }
            current->item = newElement;
        }
    }

    bool isExist(int element)
    {
        Node* current = head;
        while (current)
        {
            if (current->item == element)
                return true;
            current = current->next;
        }
        return false;
    }

    bool isItemAtEqual(int element, int index)
    {
        if (index < 0 || index >= size)
            return false;
        else
            return retrieveAt(index) == element;
    }

    void swap(int firstItemIdx, int secondItemIdx)
    {
        if (firstItemIdx < 0 || firstItemIdx >= size || secondItemIdx < 0 || secondItemIdx >= size)
            return;

        if (firstItemIdx == secondItemIdx)
            return;

        Node* first = head;
        for (int i = 0; i < firstItemIdx; ++i)
        {
            first = first->next;
        }
        Node* second = head;
        for (int i = 0; i < secondItemIdx; ++i)
        {
            second = second->next;
        }
        int temp = first->item;
        first->item = second->item;
        second->item = temp;
    }

    bool isEmpty() const
    {
        return size == 0;
    }

    int linkedListSize() const
    {
        return size;
    }

    void clear()
    {
        while (head)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

    void print()
    {
        Node* current = head;
        while (current)
        {
            cout<<current->item <<' ';
            current = current->next;
        }
        cout<<'\n';
    }

    ~DoubleLinkedList()
    {
        clear();
    }
};

int main()
{

}
