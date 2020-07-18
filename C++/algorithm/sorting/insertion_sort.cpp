#include <iostream>

using namespace std;

template <typename T>
void insertionSort(T *arr, int n)
{
    int k;
    T key;
    for (int j = 1; j < n; j++)
    {
        k = j - 1;
        key = arr[j];
        while (k >= 0 && key < arr[k])
        {
            arr[k + 1] = arr[k];
            k--;
        }
        arr[k + 1] = key;
    }
}

int main()
{
    string arr[] = {"shivam", "shubham", "bhuvnesh"};

    insertionSort<string>(arr, 3);

    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}