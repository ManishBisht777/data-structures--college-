#include <iostream>
using namespace std;

class Node
{
public:
    int row;
    int col;
    int data;
    Node *next;
};

void create_new_node(Node **p, int row_index,
                     int col_index, int x)
{
    Node *temp = *p;
    Node *r;

    if (temp == NULL)
    {
        temp = new Node();
        temp->row = row_index;
        temp->col = col_index;
        temp->data = x;
        temp->next = NULL;
        *p = temp;
    }

    // If link list is already created
    // then append newly created node
    else
    {
        while (temp->next != NULL)
            temp = temp->next;

        r = new Node();
        r->row = row_index;
        r->col = col_index;
        r->data = x;
        r->next = NULL;
        temp->next = r;
    }
}

void printList(Node *start)
{
    Node *ptr = start;
    cout << "\n\t row position    : ";
    while (ptr != NULL)
    {
        cout << ptr->row << " ";
        ptr = ptr->next;
    }
    cout << endl;
    cout << "\n\t column position :";

    ptr = start;
    while (ptr != NULL)
    {
        cout << ptr->col << " ";
        ptr = ptr->next;
    }
    cout << endl;
    cout << "\n\t Value           : ";
    ptr = start;

    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int getval(Node *head, int row, int col)
{
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->row == row && temp->col == col)
        {
            return temp->data;
        }
        temp = temp->next;
    }
    return 0;
}

int main()
{

    int sparseMatrix[4][5] = {{0, 0, 3, 0, 4},
                              {0, 0, 5, 7, 0},
                              {0, 0, 0, 0, 0},
                              {0, 2, 6, 0, 0}};

    Node *first = NULL;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {

            if (sparseMatrix[i][j] != 0)
                create_new_node(&first, i, j,
                                sparseMatrix[i][j]);
        }
    }
    printList(first);
    cout << "\n\n\t value at given position : "
         << getval(first, 0, 2);
    getval(first, 0, 0);
    return 0;
}
