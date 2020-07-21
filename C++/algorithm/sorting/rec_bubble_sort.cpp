#include <iostream>
#include <algorithm>
using namespace std;

// Recursive Approach Bubble Sort
void bubble_sort(int *arr, int i, int n)
{

    cout << "n: " << n;
    cout << " i: " << i << endl;

    if (n == 1)
        return;

    if (i == n - 1)
        bubble_sort(arr, 0, n - 1);

    else
    {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
        bubble_sort(arr, i + 1, n);
    }
}

int main()
{

    int arr[] = {5, 4, 3, 2, 1};

    int n = sizeof(arr) / sizeof(int);

    bubble_sort(arr, 0, n);
    cout << endl;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}