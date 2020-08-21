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

int clear_to_ith_bit(int n, int i)
{
    // Need Mask of form -> 111000
    // ~0 -> ~(0000) = 1111111
    // Left Shift this till i mask << i
    return (n & (-1 << i));
}

int clear_range_bit(int n, int i, int j)
{
    return (n & ((-1 << j + 1) | (~(-1 << i + 1))));
}

int replace_bits_number(int n, int m, int i, int j)
{
    int n_ = clear_range_bit(n, i, j);
    return (n | (m << i));
}

// O(logN)
int count_set_bits(int n)
{
    if (n && !(n & (n - 1)))
        return 1;
    int c = 0;
    while (n > 0)
    {
        c += (n & 1);
        n >>= 1;
    }
    return c;
}

// O(no of set bits)
int count_set_bits_fast(int n)
{
    // n & (n-1) -> this line removes the set bits from left to right
    // This line was also used to check whether the number is power of two
    // Example
    //  111 -> 7
    // &110 -> 6
    //  110 -> This removed the first bit from 7 left to right
    // &101 -> 5
    //  100 -> Removed the first bit from 6
    int a = 0;
    while (n > 0)
    {
        n &= (n - 1);
        a++;
    }

    return a;
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
    int n = clear_range_bit(no, 1, 2);
    cout << n << endl;
    cout << count_set_bits(16) << endl;
    cout << count_set_bits_fast(16) << endl;

    // This is the built in fn for set bit count
    cout << __builtin_popcount(16) << endl;

    return 0;
}