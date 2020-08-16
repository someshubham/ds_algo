#include <iostream>
#include <vector>
using namespace std;

// Problems using Bit Masking / Manipulation

// 1. Unique Number Soln
int find_unique(vector<int> arr)
{
    int ans = 0;
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        ans ^= *it;
    }

    return ans;
}

int main()
{
    // 1. Unique Number Input
    vector<int> arr{1, 1, 2, 3, 3};
    int ans = find_unique(arr);
    cout << ans << endl;
    return 0;
}