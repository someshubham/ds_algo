#include <iostream>
#include <cmath>
#define ll long long int
#define k 13
using namespace std;

ll calculate_hash(string str, int n)
{
    ll hashValue = 0;

    for (int i = 0; i < n; i++)
    {
        hashValue += str[i] * pow(k, i);
    }

    return hashValue;
}

void rabin_karp_string_match(string text, string ptrn)
{

    int n = text.length();
    int m = ptrn.length();

    ll pHash = calculate_hash(ptrn, m);
    ll tHash = calculate_hash(text, m);

    for (int i = 0; i <= n - m; i++)
    {

        if (pHash == tHash)
        {
            bool isMatch = true;
            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != ptrn[j])
                {
                    isMatch = false;
                    break;
                }
            }
            if (isMatch)
            {
                cout << "Index is :" << i << endl;
            }
        }

        tHash = ((tHash - text[i]) / k) + (text[i + m] * pow(k, m - 1));
    }
}

int main()
{
    rabin_karp_string_match("SHUBHAM", "BHAM");
    return 0;
}