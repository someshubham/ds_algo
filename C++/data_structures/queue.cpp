#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    Node<T> *link;
    T value;
};

template <typename T>
class Queue
{
private:
    Node<T> *front;
    Node<T> *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void push(T value)
    {
        Node<T> *newNode = new Node<T>;
        newNode->value = value;
        newNode->link = NULL;
        if (front == NULL && rear == NULL)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->link = newNode;
            rear = newNode;
        }
    }

    T pop()
    {
        if (front == NULL && rear == NULL)
        {
            cout << "Underflow" << endl;
            return 0;
        }
        else
        {
            Node<T> *temp = front;
            if (front == rear)
            {
                front = NULL;
                rear = NULL;
            }
            else
            {
                front = front->link;
            }
            //rear = NULL;

            T value = temp->value;
            free(temp);
            return value;
        }
    }

    void printQueue()
    {
        Node<T> *t = front;
        // Traverse to the end of the list while the pointer is not null
        while (t != NULL)
        {
            cout << t->value << " ";
            t = t->link;
        }
        cout << endl;
    }
};

int main()
{
    Queue<int> q;

    q.push(40);
    q.push(20);
    q.push(30);
    q.pop();
    q.pop();
    q.pop();
    q.push(10);
    q.printQueue();
    // q.push(20);

    return 0;
}