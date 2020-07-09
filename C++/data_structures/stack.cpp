/*
Implementing Stacks in C++

We will use LinkedList style Data Structure


*/

#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    Node *link;
    T value;
};

template <typename T>
class Stack
{
private:
    int stackSize;
    Node<T> *topElement;

public:
    Stack()
    {
        stackSize = 0;
        topElement = NULL;
    }

    void push(T value)
    {
        // This is the old C way of dynamic memory allocation
        Node<T> *newNode = new Node<T>;
        newNode->value = value;
        newNode->link = topElement;
        topElement = newNode;
        stackSize++;
    }

    T pop()
    {
        Node<T> *t = topElement;
        T value = t->value;
        topElement = topElement->link;
        // Free Up the Space when not in use
        // Old C way for freeing up space
        free(t);
        stackSize--;
        return value;
    }

    T top()
    {
        return topElement->value;
    }

    int size()
    {
        return stackSize;
    }

    bool empty()
    {
        return stackSize == 0 ? true : false;
    }
};

int main()
{
    Stack<int> stack;
    stack.push(30);
    stack.push(20);
    stack.push(10);
    cout << stack.empty() << endl;
    cout << stack.pop() << endl;
    cout << stack.top() << endl;
    cout << stack.pop() << endl;
    cout << stack.empty() << endl;
    cout << stack.pop() << endl;
    cout << stack.empty() << endl;
    return 0;
}