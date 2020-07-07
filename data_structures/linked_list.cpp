#include <iostream>

using namespace std;
/*
This file contains the linked List implementation using classes and structures

We are using the arrow operator '->' instead of '(*).'

For eg - 

struct node* p = &a ; // a is some node

Then we have to ways to access 'a'

 (*p).value; // Using *p we get the access to the a and ' . ' operator gets the value

 brackets are used because ' . ' has higher priority than '*'

 therefore we use a shorter format to clean up code as -

 p->value; // This is same as (*p).value


*/

// Create a node structure with value and a pointer to the next structure
struct node
{
    struct node *link;
    int value;
};

// Rename the struct node as node
typedef struct node node;

// Class for the linkedList contains all the function implementations
class LinkedList
{
private:
    node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insertAtStart(int value)
    {
        // This is the old C way of dynamic memory allocation
        node *newNode = (node *)malloc(sizeof(node));
        newNode->value = value;
        newNode->link = head;
        head = newNode;
    }

    int deleteAtStart()
    {
        node *t = head;
        int value = t->value;
        head = head->link;
        // Free Up the Space when not in use
        // Old C way for freeing up space
        free(t);
        return value;
    }

    void insertAtEnd(int value)
    {
        // This is the new way of C++ for dynamic memory allocation
        node *newNode = new node;
        newNode->value = value;
        node *t = head;
        while (t->link)
        {
            t = t->link;
        }
        t->link = newNode;
        newNode->link = NULL;
    }

    int deleteAtEnd()
    {
        node *t = head;
        while (t->link->link)
        {
            t = t->link;
        }
        node *t2 = t->link;
        int value = t2->value;
        t->link = NULL;
        // Free Up the Space when not in use
        // New C++ way for freeing up space
        delete t2;
        return value;
    }

    void printList()
    {
        node *t = head;
        // Traverse to the end of the list while the pointer is not null
        while (t)
        {
            cout << t->value << " ";
            t = t->link;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list;

    list.insertAtStart(10);
    list.insertAtStart(20);
    list.insertAtStart(50);
    list.insertAtEnd(30);
    list.printList();
    cout << "Deleted At the End :" << list.deleteAtEnd() << endl;
    cout << "Deleted At the End :" << list.deleteAtStart() << endl;
    list.printList();
    return 0;
}