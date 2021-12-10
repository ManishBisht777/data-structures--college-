#include <iostream>
using namespace std;

class Queue
{
public:
    int *arr;
    int size, head = -1, tail = -1;
};

void display(Queue **A)
{
    cout << endl
         << endl;
    int i = (*A)->head + 1;
    while (i != (*A)->tail)
    {
        cout << "--" << (*A)->arr[i];
        i = (i + 1) % (*A)->size;
    }
    cout << "--" << (*A)->arr[(*A)->tail];
    cout << endl;
}

bool isEmpty(Queue **a)
{
    if ((*a)->head == (*a)->tail)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(Queue **a)
{
    if (((*a)->tail + 1) % (*a)->size == (*a)->head)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(Queue **a, int num)
{
    if (isFull(a))
    {
        cout << "\nQueue overflow";
        return;
    }
    if ((*a)->head == -1 && (*a)->tail == -1)
    {
        (*a)->head = 0, (*a)->tail = 0;
    }
    (*a)->tail = ((*a)->tail + 1) % (*a)->size;
    (*a)->arr[(*a)->tail] = num;
}

void dequeue(Queue **a)
{
    if (isEmpty(a))
    {
        cout << "\nQueue underflow";
        return;
    }
    ++(*a)->head;
    (*a)->head = (*a)->head % (*a)->size;
    cout << '\n'
         << (*a)->head;
}

void peek(Queue **a)
{
    if (isEmpty(a))
    {
        cout << "\nEmpty Queue";
        return;
    }
    cout << "\n"
         << (*a)->arr[(*a)->head + 1];
}

int main()
{
    Queue *q = new Queue;
    q->size = 5;
    q->arr = new int[q->size];
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    dequeue(&q);
    enqueue(&q, 5);
    dequeue(&q);
    enqueue(&q, 6);
    enqueue(&q, 7);
    display(&q);
}