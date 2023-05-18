#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string s;
    int n;
    int half;
    int cntT = 0;
    int cntA = 0;
    bool T = false;
    bool A = false;
    cin >> n >> s;
    half = n / 2;
    rep(i, n)
    {
        if(s[i] == 'T')
        {
            cntT++;
        }
        else
        {
            cntA++;
        }
        if(cntT == half && !A)
        {
            T = true;
        }
        if(cntA == half && !T)
        {
            A = true;
        }
    }
    if(cntT > cntA)
    {
        cout << "T\n";
    }
    else if(cntA > cntT)
    {
        cout << "A\n";
    }
    else
    {
        if(T)
        {
            cout << "T\n";
        }
        if(A)
        {
            cout << "A\n";
        }
    }
    return 0;
}