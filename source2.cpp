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
    }

    // read fraction
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
    }

    // write fraction
    void write()
    {
        cout << numerator << "/" << denominator << endl;
    }

    // The two parameters are two fractions, the function returns the biggest fraction 
    Fraction max(const Fraction& a, const Fraction & b) const
    {
        if (a.numerator * b.denominator > a.denominator * b.numerator)
            return a;
        
        return b;
    }
};

int main()
{   
    Fraction a, b, MAX;
    cout << "ENTER THE FIRST FRACTION" << endl;
    a.read();
    cout << "ENTER THE SECOND FRACTION" << endl;
    b.read();

    cout << "The biggest fraction: ";
    MAX = MAX.max(a, b);
    MAX.write();
    return 0;
}