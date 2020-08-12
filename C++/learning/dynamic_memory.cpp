#include <iostream>

using namespace std;

// Dynamic Allocation Or Run Time Allocation

// Uses Heap Memory
// Heap is bigger than the static memory

int main()
{
    int *x = new int;

    *x = 10;

    // x will be stored in static memory
    // and x is a pointer pointing to memory area in the heap

    cout << *x << endl;
    cout << x << endl;

    // This is usually used for arrays , but will be using vectors lol

    // Here arr is not an array but a pointer to the array
    // So sizeof will give u size of the pointer
    // We have to free up the memory to avoid memory leak
    int n;
    cin >> n;
    int *a = new int[n]{0};

    // Create 2D Array
    int **arr;
    int r, c;
    cin >> r >> c;

    arr = new int *[r];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[c]{0};
    }

    //Take input
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Free Up Memory
    delete x;
    delete[] a;
    return 0;
}