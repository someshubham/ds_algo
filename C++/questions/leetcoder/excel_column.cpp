#include <iostream>
#include <cstring>
#include <stack>
#define ALPHA 26
#define LETTER 64
using namespace std;

// https://leetcode.com/problems/excel-sheet-column-title/

string excel_column(int n)
{
    stack<char> cS;
    int r = 0;
    char s;
    string ans;
    do
    {
        s = LETTER;
        r = n % ALPHA;
        n /= ALPHA;

        if (r == 0)
        {
            n = n - 1;
            r = ALPHA;
        }
        s += r;
        cS.push(s);

    } while (n > 0);
    while (!cS.empty())
    {
        ans += cS.top();
        cS.pop();
    }
    return ans;
}

int main()
{
    cout << excel_column(702) << endl;
    return 0;
}