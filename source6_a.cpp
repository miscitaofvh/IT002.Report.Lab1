#include <bits/stdc++.h>

using namespace std;

// Create table LPS for a
vector<int> buildLPS(const vector<int>& a) {
    int n = a.size();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;

    while (i < n) {
        if (a[i] == a[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// Check all positions of a in b
void kmpSearch(const vector<int>& a, const vector<int>& b) {
    int n = a.size();
    int m = b.size();
    
    if (n > m) {
        cout << "Array A does not exist in array B" << endl;
        return;
    }

    vector<int> lps = buildLPS(a);
    int i = 0;
    int j = 0; 

    vector<int> positions; 

    while (i < m) {
        if (a[j] == b[i]) {
            i++;
            j++;
        }

        if (j == n) {
            positions.push_back(i - j);
            j = lps[j - 1];
        } else if (i < m && a[j] != b[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    if (positions.empty()) {
        cout << "Array A does not exist in array B" << endl;
    } else {
        cout << "Array A appears in positions: ";
        for (int pos : positions) {
            cout << pos << " ";
        }
        cout << endl;
    }
}

vector<int> a, b;
int nA, nB;

int main() 
{
    cout << "Enter size of array A: ";
    cin >> nA;
    a.resize(nA);
    for (int i = 0; i < nA; ++i)
    {
        cout << "A[" << i + 1 << "]= ";
        cin >> a[i];
    }

    cout << "Enter size of array B: ";
    cin >> nB;
    b.resize(nB);
    for (int i = 0; i < nB; ++i)
    {
        cout << "A[" << i + 1 << "]= ";
        cin >> b[i];
    }
    
    kmpSearch(a, b);

    return 0;
}
