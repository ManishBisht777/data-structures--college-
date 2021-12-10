#include <iostream>
using namespace std;
template <class T>
class sorting
{
    T a[10];

public:
    void get_item()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << "\n a[" << i << "] = ";
            cin >> a[i];
        }
    }
    void sel_sort()
    {
        T temp;
        for (int i = 0; i < 10; i++)
        {
            for (int j = i + 1; j < 10; j++)
            {
                if (a[i] > a[j])
                {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
    void bub_sort()
    {
        T temp;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10 - i - 1; j++)
            {
                if (a[j] > a[j + 1])
                {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
    }
    void inst_sort()
    {
        T tmp;
        int j;
        for (int i = 1; i < 10; i++)
        {
            tmp = a[i];
            j = i - 1;
            while (tmp < a[j])
            {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = tmp;
        }
    }
    void display()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << " " << a[i] << ", ";
        }
        cout << "\n\n";
    }
};
int main()
{
    // Creating Integer Array using Template
    sorting<int> iarr;
    cout << "\n\n Enter Elements of Integer Array\n";
    iarr.get_item();
    cout << "\n\n Elements of Integer Array\n";
    iarr.display();
    int ch;
    int choice;
    do
    {
        cout << "\n\t 1---> bubble sort \n\t 2---> Insertion sort \n\t 3---> selection sort";
        cout << "\n\t\t Enter your choice : ";

        switch (choice)
        {
        case 1:
            iarr.sel_sort();
            cout << "\n\t After Selection Sorting Elememts of Integer Array : ";
            iarr.display();
            break;
        case 2:
            iarr.bub_sort();
            cout << "\n\t After Bubble Sorting Elememts of Integer Array : ";
            iarr.display();
            break;
        case 3:
            iarr.inst_sort();
            cout << "\n\t After Insertion Sorting Elememts of Integer Array : ";
            iarr.display();
            break;

        default:
            break;
        }

        cout << "\n\t do you want to continue : ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');

    return 0;
}
