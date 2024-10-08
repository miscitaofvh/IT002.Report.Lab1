#include <bits/stdc++.h>

using namespace std;

int x;
int main()
{
    cout << "Enter x: ";   
    cin >> x;

    long double i = 0;
    long double sign = 1;
    long double ans = 0;
    long double current = x;
    do
    {
        ans += sign * current;  
        i += 1;
        current *= x * x;
        current /= 2 * i * (2 * i + 1);
        sign *= -1;
    }
    while (abs(current) > 0.000001);

    cout << "Sin(" << x << ") = " << fixed << setprecision(5) << ans << endl;
}