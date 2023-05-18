#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    bool flag = false;
    cin >> n;
    string s[100];
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for(int j = 0; j < n;j++)
    {
        if(s[j] == "and" || s[j] == "not" || s[j] == "that" || s[j] == "the" || s[j] == "you")
        {
            flag = true;
        }
    }
    if(flag)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}