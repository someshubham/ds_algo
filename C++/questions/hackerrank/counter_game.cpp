#include <bits/stdc++.h>

using namespace std;

// Problem URL
// https://www.hackerrank.com/challenges/counter-game/problem

// Function to check whether it is a power of two
bool isPowerTwo(long n)
{
    return n && !(n & (n - 1));
}

// Get MSB of the number
long getNextPower(long n)
{
    long a = (long)(log2(n));

    return (long)(pow(2, a));
}

// Complete the counterGame function below.
string counterGame(long n)
{
    int turn = 0;
    if (n == 1)
    {
        return "Louise";
    }
    while (n > 1)
    {
        if (isPowerTwo(n))
            n >>= 1;
        else
            n -= getNextPower(n);
        if (n != 1)
            turn++;
    }
    if (turn % 2 == 0)
        return "Louise";
    else
        return "Richard";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = counterGame(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
