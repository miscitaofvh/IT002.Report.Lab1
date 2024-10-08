#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, d;

    cout << "Enter the numerator of the first fraction: ";
    cin >> a;
    cout << "Enter the denominator of the first fraction: ";
    cin >> b;
    while (b == 0)
    {
        cout << "Fractions cannot have a denominator of 0";
        cout << "Enter again: ";
        cin >> b;
    }
    cout << "Enter the numerator of the seccond fraction: ";
    cin >> c;
    cout << "Enter the denominator of the second freaction: ";
    cin >> d;

    while (d == 0)
    {
        cout << "Fractions cannot have a denominator of 0";
        cout << "Enter again: ";
        cin >> d;
    }

    long double firstFraction = (long double) a / b;
    long double secondFraction = (long double) c / d;

    if (firstFraction > secondFraction)
        cout << "The greater fraction is: " << a << "/" << b << endl;
    else 
        cout << "The greater fraction is: " << c << "/" << d << endl;
    return 0;
}