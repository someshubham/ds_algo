#include <iostream>
#include <algorithm>
using namespace std;

/*

This is my take on frequency sort

This is in no way optimized

Would use STL next time to optimize it

First I sort the array then i shift the numbers based on their lengths


*/

void frequency_sort(int *arr, int n)
{
    sort(arr, arr + n);

    int max, i, l, j, key;

    for (int h = 0; h < n / 2; h++)
    {
        max = 0;
        l = 1;
        i = 0;
        // Main Shifting logic
        // This is sort of a O(n+m) movement n for the i and m for the shifting
        while (i < n)
        {
            j = i;
            // count the occurence
            while (arr[j] == arr[j + 1])
            {
                l++;
                j++;
            }
            // Check the length from the previous and shift
            if (l >= max)
            {
                max = l;
            }
            else
            {

                key = arr[j];
                // Shifting
                for (int k = i - max; k < i; k++)
                {
                    arr[k + l] = arr[k];
                }
                //Copying
                for (int k = i - max; k < i - max + l; k++)
                {
                    arr[k] = key;
                }
            }
            l = 1;
            i = j + 1;
        }
    }
}

int main()
{
    int arr[] = {3, 1, 1, 2, 2, 1};
    int n = sizeof(arr) / sizeof(int);
    frequency_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}