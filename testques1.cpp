#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertattail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
}

void insertathead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void positivenegative(node *&head, node *&pos, node *&neg)
{
    node *temp = head;
    node *p1 = pos;
    node *p2 = neg;
    while (temp != NULL)
    {
        if ((temp->data) < 0)
        {
            if (p2 == NULL)
            {
                insertathead(neg, temp->data);
            }
            else
            {
                insertattail(neg, temp->data);
            }
        }
        else
        {
            if (p1 == NULL)
            {
                insertathead(pos, temp->data);
            }
            else
            {
                insertattail(pos, temp->data);
            }
        }
        temp = temp->next;
    }
}

void display(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL \n";
}

int main()
{
    node *head = NULL;
    node *pos = NULL;
    node *neg = NULL;
    insertattail(head, 1);
    insertattail(head, -2);
    insertattail(head, 3);
    insertattail(head, -4);
    positivenegative(head, pos, neg);
    cout << "\n\t Original Linked list : ";
    display(head);
    cout << "\n\t Linked list with positive Numbers : ";
    display(pos);
    cout << "\n\t Linked list with positive Numbers : ";
    display(neg);
}