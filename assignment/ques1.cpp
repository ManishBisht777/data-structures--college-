#include <bits/stdc++.h>
using namespace std;

class nodeList
{
public:
    int age, salary;
    string name;
    nodeList *next;
};

void display(nodeList *head)
{
    head = head->next;
    while (head != NULL)
    {
        cout << "\n\t Age : ";
        cout << head->age;
        cout << endl;
        cout << "\n\t Name:";
        cout << head->name;
        cout << endl;
        cout << "\n\t Salary:";
        cout << head->salary;
        cout << endl;
        head = head->next;
    }
    cout << endl;
}

void insertEmp(nodeList **head, int salary, string name, int age)
{
    nodeList *ptr = (*head);
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    nodeList *newElem = new nodeList;
    newElem->salary = salary;
    newElem->name = name;
    newElem->age = age;
    ptr->next = newElem;
    newElem->next = NULL;
}

void sort(nodeList **head)
{
    nodeList *temp = (*head)->next;
    string nam1, nam2;
    while (temp != NULL)
    {
        nodeList *ptr = temp->next;
        while (ptr != NULL)
        {
            nam1 = temp->name;
            nam2 = ptr->name;
            if (nam1 > nam2)
            {
                int temp1 = temp->age;
                int temp2 = temp->salary;
                temp->name = nam2;
                temp->age = ptr->age;
                temp->salary = ptr->salary;
                ptr->name = nam1;
                ptr->age = temp1;
                ptr->salary = temp2;
            }
            ptr = ptr->next;
        }
        temp = temp->next;
    }
}

int main()
{
    nodeList *myEmp = new nodeList;
    string tempName;
    int tempAge, tempSalary, n;
    cout << "\n\t Enter number of entries :";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\n\t Enter Name : ";
        cin >> tempName;
        cout << " \n\t Enter Age : ";
        cin >> tempAge;
        cout << "\n\t Enter Salary : ";
        cin >> tempSalary;
        insertEmp(&myEmp, tempSalary, tempName, tempAge);
    }

    cout << "\n\n\t\t <------DETAILS ARE ------>\n\t";
    sort(&myEmp);
    display(myEmp);
}