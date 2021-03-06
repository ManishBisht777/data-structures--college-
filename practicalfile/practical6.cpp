#include <iostream>
using namespace std;

class stack
{
    int *ar;
    int size;
    int top;

public:
    stack();
    void push(int a);
    int pop();
    bool isempty();
    bool isfull();
    int topel();
    void clear();
};

stack::stack()
{
    cout << "Enter the size of the stack: ";
    cin >> size;
    top = -1;
    ar = new int[size];
    return;
}

void stack::push(int a)
{
    if (isfull())
    {
        cout << "\nStack Overflow!!\n";
    }
    else
    {
        ar[++top] = a;
    }
}

int stack::pop()
{
    if (isempty())
    {
        cout << "\nStack underflow!!\n";
        return -1;
    }
    else
    {
        return ar[top--];
    }
}

bool stack::isempty()
{
    return (top == -1);
}

bool stack::isfull()
{
    return (top == size - 1);
}

int stack::topel()
{
    if (isempty())
    {
        cout << "\nStack is empty!!\n";
        return -1;
    }
    else
    {
        return ar[top];
    }
}

void stack::clear()
{
    top = -1;
    return;
}

int main()
{
    stack s1;
    cout << "\nPushing 5 6 3 6 7 2 one by one\n";
    s1.push(5);
    s1.push(6);
    s1.push(3);
    s1.push(6);
    s1.push(7);
    s1.push(2);
    cout << s1.pop() << " " << s1.pop() << endl;
    cout << s1.topel() << endl;
    cout << s1.isempty();
    cout << s1.isfull() << endl;
    s1.clear();
    cout << s1.isempty() << endl;
}