#include <iostream>
#include <algorithm>
using namespace std;

// Recursive Approach to selection Sort

void selection_sort(int *arr, int i, int min_index, int n)
{
    if (n == 1)
        return;

    if (i == n)
    {
        if (arr[0] > arr[min_index])
            swap(arr[0], arr[min_index]);
        selection_sort(arr + 1, 0, 0, n - 1);
    }
    else
    {
        if (arr[i] < arr[min_index])
            min_index = i;
        selection_sort(arr, i + 1, min_index, n);
    }
}

int main()
{

    int arr[] = {5, 4, 3, 2, 1};

    int n = sizeof(arr) / sizeof(int);

    selection_sort(arr, 0, 0, n);
    cout << endl;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}