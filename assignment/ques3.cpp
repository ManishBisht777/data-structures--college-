#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next = NULL;
};

void insertAtEnd(node **head, int num)
{
    node *ptr = (*head);
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    node *newElem = new node;
    newElem->data = num;
    ptr->next = newElem;
    newElem->next = NULL;
}

void display(node *head)
{
    while (head != NULL)
    {
        if (head->data != 0 && head->data < 100)
        {
            cout << head->data;
            cout << " ";
        }
        head = head->next;
    }
    cout << endl;
}

void alterPlacement(node *l1, node *l2, node *res)
{
    while (l1 != NULL)
    {
        insertAtEnd(&res, l1->data);
        insertAtEnd(&res, l2->data);
        l1 = l1->next;
        l2 = l2->next;
    }
}

int main()
{
    node *l1 = new node;
    int arrl1[] = {7, 5, 3, 1, 20};
    for (int i = 0; i < 5; i++)
    {
        insertAtEnd(&l1, arrl1[i]);
    }
    cout << "\n\t L1 : ";
    display(l1);

    node *l2 = new node;
    int arrl2[] = {6, 25, 32, 11, 9};
    for (int i = 0; i < 5; i++)
    {
        insertAtEnd(&l2, arrl2[i]);
    }

    cout << "\n\t L2 : ";
    display(l2);
    node *res = new node;
    alterPlacement(l1, l2, res);
    cout << "\n\t\t After combination : ";
    display(res);
}