#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int b1 = 0, b2 = 0;
    int r1 = 0, r2 = 0;
    int k = 0;
    bool bflag = false;
    bool kflag = false;
    for(int i = 1; i <= 8; i++)
    {
        if((s[i - 1] == 'B') && (b1 == 0))
        {
            b1 = i;
        }
        else if(s[i - 1] == 'B')
        {
            b2 = i;
        }
        if((s[i - 1] == 'R') && (r1 == 0))
        {
            r1 = i;
        }
        else if(s[i - 1] == 'R')
        {
            r2 = i;
        }
        if(s[i - 1] == 'K')
        {
            k = i;
        }
    }
    if((b1 %2) != (b2 %2))
    {
        bflag = true;
    }
    if((r1 < k) && (k < r2))
    {
        kflag = true;
    }
    if(bflag && kflag)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}