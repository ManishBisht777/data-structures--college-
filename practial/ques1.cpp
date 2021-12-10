#include <iostream>

using namespace std;
#define SIZE 10

// global variable declaration

int A[SIZE];
int front = -1;
int rear = -1;

// checking is queue is empty or not
bool isempty()
{
    if (front == -1 && rear == -1)
        return true;
    else
        return false;
}

// insert elements in queue
void enqueue(int value)
{
    //queue is full
    if ((rear + 1) % SIZE == front)
        cout << "\n\n\t\t <<--- Queue Overflow -----> ";
    else
    {
        //first element inserted
        if (front == -1)
            front = 0;
        //insert element at rear
        rear = (rear + 1) % SIZE;
        A[rear] = value;
    }
}

// delete elements from queue

void dequeue()
{
    if (isempty())
        cout << "\n\n\t\t Queue Underflow";
    else
        //only one element
        if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

//function to show the element at front
void top()
{
    if (isempty())
        cout << "\n\n\t\t Queue Underflow";
    else
        cout << "\n\t Element at front :" << A[front];
}

//function to display queue
void display()
{
    if (isempty())
        cout << "\n\n\t\t Queue Underflow";
    else
    {
        cout << "\n\t Elements in Queue : ";
        int i;
        if (front <= rear)
        {
            for (i = front; i <= rear; i++)
                cout << A[i] << " ";
        }
        else
        {
            i = front;
            while (i < SIZE)
            {
                cout << A[i] << " ";
                i++;
            }
            i = 0;
            while (i <= rear)
            {
                cout << A[i] << " ";
                i++;
            }
        }
    }
}

//Main Function
int main()
{
    int choice, flag = 1, value;
    while (flag == 1)
    {
        cout << "\n\n\t 1 ---> Enqueue"
             << "\n\t 2 ---> Dequeue \n\t 3 ---> Top \n\t 4 ---> Display elements in queue";
        cout << "\n\t\t Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\n\t Enter Value :";
            cin >> value;
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            top();
            break;
        case 4:
            display();
            break;
        case 5:
            flag = 0;
            break;
        }
    }

    return 0;
}