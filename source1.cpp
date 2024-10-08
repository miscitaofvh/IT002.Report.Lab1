#include <bits/stdc++.h>

using namespace std;

int a, b;

int main()
{
    cout << "Enter numerator of the fraction: ";
    cin >> a;
    cout << "Enter denominator of the fraction: ";
    cin >> b;

    while (b == 0)
    {
        cout << "Fractions cannot have a denominator of 0" << endl;
        cout << "Enter again: ";
        cin >> b;
    }

    // Simplify fraction
    int _gcd = gcd(a, b);
    a /= _gcd;
    b /= _gcd;

    cout << "The fraction after being simplified is: ";

    if (b == 1)
    {
        cout << a;
    }
    else
    {
        cout << a << "/" << b;
    }
    return 0;
}