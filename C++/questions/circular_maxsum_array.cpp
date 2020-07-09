#include <iostream>
#include <climits>

using namespace std;

// This is the kandane Algorithm for finding maxSum Sub Array

// Modified it for circular array that would generate starting index
// and last index using the modulus operator
int kandaneSum(int *arr, int s, int n)
{
    int currentSum = 0;
    int maxSum = INT_MIN;
    int e = (n - 1 + s) % n;
    for (int i = s;; i = (i + 1) % n)
    {
        currentSum += arr[i];
        if (currentSum < 0)
            currentSum = 0;
        if (maxSum < currentSum)
            maxSum = currentSum;
        if (i == e)
            break;
    }
    return maxSum;
}

int main()
{
    int arr[10000], n, t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int maxValue = INT_MIN;
        int currentValue = 0;
        for (int i = 0; i < n; i++)
        {
            currentValue = kandaneSum(arr, i, n);
            if (currentValue >= maxValue)
                maxValue = currentValue;
        }

        cout << maxValue << endl;
    }

    return 0;
}