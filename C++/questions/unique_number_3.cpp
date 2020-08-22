#include <iostream>
#include <vector>
using namespace std;

// Unique Number 3
// 2 2 2 1 1 1 3 -> Answer is 3
// 1 2 1 1 -> Answer is 2

//Soln ->
/*
    1 -> 0 0 1
    2 -> 0 1 0
    1 -> 0 0 1
    1 -> 0 0 1
         0 1 3
         Answer -> 0 1 3 is of the form -> 3n or 3n+1
         Mod the ans -> 0 1 0 = 2 (mod with 3 each individual character)
         This soln can work with 5n , 5n+1 , 7n ...
*/

int main()
{

    vector<int> c(64, 0);
    int n, a, b, j;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        j = 0;
        while (a > 0)
        {
            b = a & 1;
            c[j++] += b;
            a >>= 1;
        }
    }
    int p = 1;
    a = 0;
    for (int i = 0; i < 64; i++)
    {
        c[i] %= 3;
        a += (c[i] * p);
        p <<= 1;
    }

    cout << a;

    return 0;
}