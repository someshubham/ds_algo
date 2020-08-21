#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> a(n);
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        x ^= a[i];
    }
    int p = 0;
    while ((x & 1) != 1)
    {
        p++;
        x >>= 1;
    }

    int m = 1 << p;
    int b = 0;
    for (int i = 0; i < n; i++)
    {
        if ((a[i] & m) > 0)
        {
            b ^= a[i];
        }
    }

    int c = b ^ x;

    cout << min(b, c) << " " << max(b, c) << endl;
    return 0;
}