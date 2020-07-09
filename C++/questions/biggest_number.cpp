#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/*

Given a list of numbers Arrange them in a way that
biggest number can be formed

Soln -
Sort the Array in a lexiographical way
also combine two strings in two ways and whichever is the biggest
will come first


*/

int myCompare(string X, string Y)
{
    // first append Y at the end of X
    string XY = X.append(Y);

    // then append X at the end of Y
    string YX = Y.append(X);

    // Now see which of the two formed numbers is greater
    return XY.compare(YX) > 0 ? 1 : 0;
}

void printBiggestNumber()
{
    int n;
    cin >> n;
    cin.get();

    string a[10000];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n, myCompare);

    for (int i = 0; i < n; ++i)
        cout << a[i];
}

int main()
{
    int t;
    cin >> t;
    for (int x = 0; x < t; x++)
    {
        printBiggestNumber();
    }

    return 0;
}