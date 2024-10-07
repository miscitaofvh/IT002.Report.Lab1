//sun's code
#include <bits/stdc++.h>

using namespace std;

class Fraction{
private:
    int numerator, denominator;
public:
    Fraction(int _numerator = 0, int _denominator = 1)
    {
        // Fractions cannot have a denominator of 0
        if (_denominator == 0) return;
        numerator = _numerator;
        denominator = _denominator;
        simplify();
    }

    // Simplify fraction
    void simplify()
    {
        int _gcd = std::gcd(numerator, denominator);
        numerator /= _gcd;
        denominator /= _gcd;
    }

    // read fraction and simplify it
    // if denominator equal 0, require enter it again
    void read()
    {
        cout << "Enter numerator of the fraction: ";
        cin >> numerator;
        cout << "Enter denominator of the fraction: ";
        cin >> denominator;

        while (denominator == 0)
        {
            cout << "Fractions cannot have a denominator of 0" << endl;
            cout << "Enter again: ";
            cin >> denominator;
        }
        
        simplify();
    }

    // write fraction
    void write()
    {
        cout << "The fraction after being simplified is: ";
        
        if (denominator == 1)
            cout << numerator;
        else
            cout << numerator << "/" << denominator;
    }
};

int main()
{   
    Fraction a;
    a.read();
    a.write();
    return 0;
}