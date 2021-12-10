#include <iostream>

using namespace std;

class node
{
public:
    int row;
    int col;
    int data;
    node *next;

    node(int rowi, int coli, int val)
    {
        row = rowi;
        col = coli;
        data = val;
        next = NULL;
    }
};

void insertattail(node *&head, int rowi, int coli, int val)
{
    node *n = new node(rowi, coli, val);

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

void insertathead(node *&head, int rowi, int coli, int val)
{
    node *n = new node(rowi, coli, val);
    n->next = head;
    head = n;
}

void display(node *&head)
{
    node *ptr = head;
    cout << "\n\t row position    : ";
    while (ptr != NULL)
    {
        cout << ptr->row << " ";
        ptr = ptr->next;
    }
    cout << endl;
    cout << "\n\t column position : ";

    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->col << " ";
        ptr = ptr->next;
    }
    cout << endl;
    cout << "\n\t Value           : ";
    ptr = head;

    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

void addsparse(node *&head1, node *&head2, node *&add, node *&sub)
{
    node *p1 = head1;
    node *p2 = head2;
    node *p3 = add;
    node *p4 = sub;

    while (p1 != NULL && p2 != NULL)
    {
        if ((p1->row == p2->row) && (p1->col == p2->col))
        {
            if (p3 == NULL && p4 == NULL)
            {
                insertathead(add, p1->row, p1->col, p1->data + p2->data);
                insertathead(sub, p1->row, p1->col, p1->data - p2->data);
            }

            else
            {
                insertattail(add, p1->row, p1->col, p1->data + p2->data);
                insertattail(sub, p1->row, p1->col, p1->data - p2->data);
            }
        }
        else
        {
            if (p3 == NULL && p4 == NULL)
            {
                insertathead(add, p1->row, p1->col, p1->data);
                insertathead(add, p2->row, p2->col, p2->data);
                insertathead(sub, p1->row, p1->col, p1->data);
                insertathead(sub, p2->row, p2->col, p2->data);
            }
            else
            {
                insertattail(add, p1->row, p1->col, p1->data);
                insertattail(add, p2->row, p2->col, p2->data);
                insertattail(sub, p1->row, p1->col, p1->data);
                insertattail(sub, p2->row, p2->col, p2->data);
            }
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    while (p1 != NULL)
    {
        insertattail(add, p1->row, p1->col, p1->data);
        insertattail(sub, p1->row, p1->col, p1->data);
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        insertattail(add, p2->row, p2->col, p2->data);
        insertattail(sub, p2->row, p2->col, p2->data);
        p2 = p2->next;
    }
}
int main()
{
    int matrix1[4][5] = {{0, 0, 3, 0, 4},
                         {0, 0, 5, 7, 0},
                         {0, 0, 0, 0, 0},
                         {0, 2, 6, 0, 0}};

    int matrix2[4][5] = {{0, 1, 3, 0, 4},
                         {0, 1, 0, 7, 0},
                         {0, 0, 0, 0, 0},
                         {0, 2, 6, 0, 0}};

    node *head1 = NULL;
    node *head2 = NULL;
    node *add = NULL;
    node *sub = NULL;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {

            if (matrix1[i][j] != 0)
            {
                insertathead(head1, i, j, matrix1[i][j]);
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {

            if (matrix2[i][j] != 0)
            {
                insertathead(head2, i, j, matrix2[i][j]);
            }
        }
    }

    cout << "\n\t <--sparse matrix 1 -->\n";
    display(head1);
    cout << "\n\n\t <--sparse matrix 2 -->\n";
    display(head2);
    addsparse(head1, head2, add, sub);

    cout << "\n\n\t <--addition of sparse matrix-->\n";
    display(add);
    cout << "\n\n\t <--subtraction of sparse matrix-->\n";
    display(sub);
}