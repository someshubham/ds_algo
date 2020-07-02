#include <iostream>
#include <climits>

using namespace std;

// This is the kandane Algorithm for finding maxSum Sub Array
// Added Long Long int for the constraints

int kandaneSum(int *arr, int s, long long int n)
{
    int currentSum = 0;
    int maxSum = INT_MIN;
    long long int e = (n - 1 + s) % n;
    for (long long int i = s;; i = (i + 1) % n)
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
    int arr[100000], t;
    long long int n;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        cin >> n;
        for (long long int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << kandaneSum(arr, 0, n) << endl;
    }

    return 0;
}