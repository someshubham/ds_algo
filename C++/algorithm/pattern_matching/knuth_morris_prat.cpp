#include <iostream>
#include <cstring>
using namespace std;

void compute_lps_array(string ptrn, int m, int *lps)
{
    int i = 0;
    int j = 1;
    lps[0] = 0;

    while (j < m)
    {

        if (ptrn[i] == ptrn[j])
        {
            i++;
            lps[j] = i;
            j++;
        }
        else
        {
            if (i != 0)
            {
                i = lps[i - 1];
            }
            else
            {
                lps[j] = 0;
                j++;
            }
        }
    }
}

void kmp_string_match(string text, string ptrn)
{
    int n = text.length();
    int m = ptrn.length();

    int i = 0, j = 0;

    int lps[m];

    compute_lps_array(ptrn, m, lps);

    while (i < n)
    {
        if (text[i] == ptrn[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << "Found at Index :" << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < n && text[i] != ptrn[j])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main()
{
    kmp_string_match("SHUBHAM", "SHUB");
    return 0;
}