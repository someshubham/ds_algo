#include <iostream>
#include <cstring>

using namespace std;

/*
Luke Skywalker gave Chewbacca an integer number x. Chewbacca isn't good at numbers but he loves inverting digits in them. Inverting digit t means replacing it with digit 9 - t.

Help Chewbacca to transform the initial number x to the minimum possible positive number by inverting some (possibly, zero) digits. The decimal representation of the final number shouldn't start with a zero.

Input Format
The first line contains a single integer x (1 ≤ x ≤ 10^18) — the number that Luke Skywalker gave to Chewbacca.



Soln -

Take number as a string in the input then convert the char into number and convert
*/

int main()
{

    string str;
    getline(cin, str);

    for (int i = 0; str[i] != '\0'; i++)
    {
        int number = str[i] - '0';
        number = (9 - number > number) ? number : (9 - number);

        if (i == 0 && number == 0)
        {
        }
        else
            str[i] = number + '0';
        cout << str[i];
    }

    return 0;
}