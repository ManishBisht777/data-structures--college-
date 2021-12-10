#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "\n\n\t Enter the Size of the Matrix : ";
    int n;
    cin >> n;
    int mat1[n][n];
    int choice;
    char ch;
    cout << "\n\t Enter elements in array : ";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mat1[i][j];
        }
    }

    do
    {
        cout << "\n\t 1 ---> Print Diagonal \n\t 2 ---> Upper Triangle \n\t 3 ---> Lower Triangle \n\t 4 ---> Check for Symmetric ";
        cout << "\n\n\t\t Enter yout choice : ";
        cin >> choice;
        if (choice == 1)
        {
            int mat[n];
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i == j)
                    {
                        mat[i] = mat1[i][j];
                    }
                }
            }

            cout << "\n\n\t 1-D Diagonal array : ";
            for (int i = 1; i <= n; i++)
            {
                cout << mat[i] << " ";
            }

            cout << "\n\n\t Displaying the Matrix \n\n\t";
            for (int i = 1; i <= n; i++) // To Print Diagonal Matrix
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i == j)
                    {
                        cout << mat[i] << " ";
                    }
                    else
                    {
                        cout << "0 ";
                    }
                }
                cout << "\n\t";
            }
        }
        else if (choice == 2)
        {
            int mat[n * (n + 1) / 2]; // To Print Upper Traingluar Matrix
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i <= j)
                    {
                        mat[j * (j - 1) / 2 + (i - 1)] = mat1[i][j];
                    }
                }
            }
            cout << "\n\t Upper traingle array : ";

            for (int j = 0; j < n * (n + 1) / 2; j++)
            {
                cout << mat[j] << " ";
            }
        }
        else if (choice == 3)
        {
            int mat[n * (n + 1) / 2]; // to Print lower Trainagular Matrix
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i >= j)
                    {
                        mat[i * (i - 1) / 2 + (j - 1)] = mat1[i][j];
                    }
                }
            }
            cout << "\n\t Lower traingle array ";

            for (int j = 0; j < n * (n + 1) / 2; j++)
            {
                cout << mat[j] << " ";
            }
        }
        else if (choice == 4)
        {
            int ctr = 1;
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 1; j <= n; ++j)
                {
                    if (mat1[i][j] != mat1[j][i])
                    {

                        ctr = 0;
                        break;
                    }
                }

                if (ctr == 0)
                    break;
            }

            if (ctr) //printing if matrix is symmetric
                cout << "\n\t <---- Matrix is symmetric ---->";
            else
                cout << "\n\t ##### Matrix is not symmetric #####";
        }
        else
        {
            cout << "\n\t Wrong choice ......";
        }
        cout << "\n\n\t\t Do you want to continue(y/n) : ";
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');
}