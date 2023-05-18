#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    bool good = false;
    bool bad = true;
    cin >> n >> s;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'o')
        {
            good = true;
        }
        if(s[i] == 'x')
        {
            bad = false;
        }
    }
    if(good && bad)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}