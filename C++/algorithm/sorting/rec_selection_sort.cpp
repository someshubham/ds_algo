#include <iostream>
#include <algorithm>
using namespace std;

// Recursive Approach to selection Sort
void selection_sort(int *arr, int i, int j, int n)
{
    cout << "j: " << j;
    cout << " i: " << i << endl;
    if (j == n - 1)
        return;

    if (i == n)
        return;

    if (arr[j] > arr[i])
        swap(arr[j], arr[i]);

    if (i == n - 1)
        selection_sort(arr, j + 2, j + 1, n);

    else
        selection_sort(arr, i + 1, j, n);
}

int main()
{

    int arr[] = {5, 4, 3, 2, 1};

    int n = sizeof(arr) / sizeof(int);

    selection_sort(arr, 1, 0, n);
    cout << endl;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}