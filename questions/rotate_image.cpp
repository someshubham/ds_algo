#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
Given a 2D array of size N x N. Rotate the array 90 degrees anti-clockwise.

Soln -

First Reverse each row
Then find transpose of the matrix

*/

void reverseRow(int *arr, int n)
{
    int i = 0;
    int j = n - 1;

    while (i <= j)
    {
        swap(arr[i++], arr[j--]);
    }
}

void rotateImage(int arr[][1000], int n)
{
    // reverse row
    for (int i = 0; i < n; i++)
    {
        reverseRow(arr[i], n);
    }

    //transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i <= j)
                swap(arr[i][j], arr[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int a[1000][1000], n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    rotateImage(a, n);

    return 0;
}