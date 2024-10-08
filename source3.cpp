#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, d, e, f, _gcd;

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

    if (b < 0)
        a = -a, b = -b;
    if (d < 0) 
        c = -c, d = -d;

    // Calculator the sum of two fraction
    e = a * d + c * b;
    f = b * d;

    // Simplify
    _gcd = gcd(e, f);
    e /= _gcd;
    f /= _gcd;

    cout << "The sum of two fractions is: ";

    if (f == 1)
        cout << e << endl;
    else 
        cout << e << '/' << f << endl;
    
    // Calculator the difference of two fraction
    e = a * d - c * b;
    f = b * d;

    // Simplify
    _gcd = gcd(e, f);
    e /= _gcd;
    f /= _gcd;

    cout << "The difference of two fractions is: ";

    if (f == 1)
        cout << e << endl;
    else 
        cout << e << '/' << f << endl;

    // Calculator the product of two fraction
    e = a * c;
    f = b * d;

    if (f < 0)
        e = -e, f = -f;
    // Simplify
    _gcd = gcd(e, f);
    e /= _gcd;
    f /= _gcd;

    cout << "The product of two fractions is: ";

    if (f == 1)
        cout << e << endl;
    else 
        cout << e << '/' << f << endl;

    // Calculator the quotient of two fraction
    e = a * d;
    f = b * c;

    if (f < 0)
        e = -e, f = -f;

    // Simplify
    _gcd = gcd(e, f);
    e /= _gcd;
    f /= _gcd;

    cout << "The quotient of two fractions is: ";

    if (f == 1)
        cout << e << endl;
    else 
        cout << e << '/' << f << endl;

    return 0;
}