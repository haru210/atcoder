#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string s;
    int cnt = 0;
    cin >> s;
    rep(i, 3)
    {
        if(s[i] == '1')
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}