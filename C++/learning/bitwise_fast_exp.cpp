#include <iostream>
#define ll long long
using namespace std;

// To compute a^n using bitwise in O(logN)

// Basically here we treat n as bits
// And keep multiplying 'a' with 'a'
// and if bit is one then multiple 'a' with Answer

// a = 2 , n = 2
// n = 010
// let ans = 1;
/*
First bit is 0 ->
    ans = 1;
    a = a*a => 2*2 => a = 4
Second bit is 1 ->
    ans = 1 * a = 1 * 4 = 4
    a = a*a => 4*4 => a = 16

The number is now 0 ... ans is 4    
*/

ll fast_pow(ll a, ll n)
{
    ll b = 1;
    while (n > 0)
    {

        if (n & 1)
            b *= a;
        a *= a;
        n >>= 1;
    }

    return b;
}

int main()
{
    cout << fast_pow(5, 3);
    return 0;
}