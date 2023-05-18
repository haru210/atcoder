#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    bool flag = false;
    cin >> n >> s;
    for(int i = 1; i < n; i++)
    {
        if(s[i - 1] == s[i])
        {
            flag = true;
        }
    }
    if(!flag)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}