#include <iostream>

using namespace std;

class node
{
public:
    int data = 0;
    node *next = NULL;
};

void display(node *head)
{
    head = head->next;
    while (head != NULL)
    {
        cout << head->data;
        head = head->next;
        cout << "->";
    }
    cout << "NULL" << endl;
}

void insert(node **head, int num)
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

void removerep(node **head)
{
    (*head) = (*head)->next;
    while (head != NULL)
    {
        node *ptr = (*head);
        while (ptr != NULL)
        {
            if ((*head)->data == ptr->data)
            {
                ptr = ptr->next->next;
            }
            ptr = ptr->next;
        }
        (*head) = (*head)->next;
    }
}

void common(node *l1, node *l2, node *res)
{
    node *temp1 = l1->next;
    node *temp2 = l2->next;
    while (temp1 != NULL)
    {
        node *ptr = temp2;
        while (ptr != NULL)
        {
            if (temp1->data == ptr->data)
            {
                int num = temp1->data;
                insert(&res, num);
            }
            ptr = ptr->next;
        }
        temp1 = temp1->next;
    }
}

void distinct(node *l1, node *l2, node *res)
{
    node *temp1 = l1->next;
    node *temp2 = l2->next;
    node *again = res;
    while (temp1 != NULL)
    {
        node *ptr = temp2;
        bool flag = true;
        while (ptr != NULL)
        {
            if (temp1->data == ptr->data)
            {
                flag = false;
                break;
            }
            ptr = ptr->next;
        }
        if (flag)
        {
            int num = temp1->data;
            insert(&res, num);
        }

        temp1 = temp1->next;
    }
    temp1 = l1->next;
    temp2 = l2->next;
    while (temp2 != NULL)
    {
        node *ptr = temp1;
        bool flag = true;
        while (ptr != NULL)
        {
            if (temp2->data == ptr->data)
            {
                flag = false;
                break;
            }
            ptr = ptr->next;
        }
        if (flag)
        {
            int num = temp2->data;
            insert(&res, num);
        }

        temp2 = temp2->next;
    }
}

int main()
{
    node *l1 = new node();
    int arrl1[] = {3, 7, 10, 15, 16, 9, 22, 17, 32};
    for (int i = 0; i < 9; i++)
    {
        insert(&l1, arrl1[i]);
    }
    cout << "\n\t L1 : ";
    display(l1);
    node *l2 = new node();
    int arrl2[] = {16, 2, 9, 13, 37, 8, 10, 1, 28};
    for (int i = 0; i < 9; i++)
    {
        insert(&l2, arrl2[i]);
    }
    cout << "\n\t L2 : ";
    display(l2);

    node *C = new node();
    cout << "\n\n\t Common elemets : ";
    common(l1, l2, C);
    display(C);
    node *D = new node();
    cout << "\n\t Distinct elements: ";
    distinct(l1, l2, D);
    display(D);
}