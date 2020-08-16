#include <iostream>
#include <vector>
using namespace std;

// Problems using Bit Masking / Manipulation

// 1. Unique Number Soln
int find_unique(vector<int> arr)
{
    // {2,2,1}
    // 2 ^ 2 = 0 ^ 1 = 1
    int ans = 0;
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        ans ^= *it;
    }

    return ans;
}

// Common Bit Opn

void is_odd()
{
    // Find Even and Odd
    // If the last bit is set or one then the number is odd
    // n & 1 = 1 // odd
    // n & 1 = 0 // even
    cout << "Find Even or Odd" << endl;
    int n = 5;
    if (n & 1)
    {
        cout << n << " is odd" << endl;
    }
    else
    {
        cout << n << " is even" << endl;
    }
}

int find_ith_bit(int n, int i)
{
    // Create  a mask
    //int mask = 1 << i ; // Basically this is setting the ith bit as one
    // 001 -> shift 2 -> 100
    // Suppose we want to find 2nd bit of 5
    // 00101 -> 5
    // 00100 -> Mask Created using 2 (i << 2)
    // if the answer is greater than zero then it is set else not
    return (n & (1 << i)) > 0 ? 1 : 0;
}

int set_ith_bit(int n, int i)
{
    // This is similar to find ith bit
    // Just Do OR instead of AND and we will set the bit
    // If it is already set then it will remain set
    return (n | (1 << i));
}

int clear_ith_bit(int n, int i)
{
    // Same as get ith bit just the mask is diff
    // instead of 000100 -> 111011
    // And then AND this
    return (n & ~(1 << i));
}

// set the value of the ith bit to be value
int update_ith_bit(int &n, int i, int v)
{
    n = clear_ith_bit(n, i);

    return (n | (v << i));
}

int main()
{
    // 1. Unique Number Input
    vector<int> arr{1, 1, 2, 3, 3};
    int ans = find_unique(arr);
    cout << ans << endl;
    //Common Bit Opn
    is_odd();
    int no = 5;
    int n = update_ith_bit(no, 3, 1);
    cout << n;
    return 0;
}