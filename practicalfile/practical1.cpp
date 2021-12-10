#include <iostream>
#include <algorithm>
using namespace std;

void print(int ar[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << ar[i] << " ";
    }
}

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

int main()
{
    int *ar;
    int size, search, pos;
    cout << "\n\t ENTER SIZE OF ARRAY : ";
    cin >> size;
    ar = new int[size];
    cout << "\n\t ENTER ELEMENTS OF ARRAY : \n";
    for (int i = 0; i < size; i++)
    {
        int a;
        bool flag = true;
        cin >> a;
        for (int j = i - 1; j >= 0; j--)
        {
            if (a == ar[j])
            {
                i--;
                cout << "\n\t you have entered duplicate value so it is discarded!!\n";
                flag = false;
                break;
            }
        }
        if (flag)
        {
            ar[i] = a;
        }
    }

    sort(ar, ar + size);

    cout << "\n\t ENTERED ARRAY : \n";
    print(ar, size);
    cout << endl;
    cout << "\n\t ENTER ELEMENT TO BE SEARCHED : ";
    cin >> search;
    pos = binarySearch(ar, 0, size - 1, search);
    cout << "\n\t INDEX OF SEARCHED ELEMENT : " << pos << endl;
}