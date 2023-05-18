#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
//各文字の数を調べ上げ、各文字の差をとる作戦
int main()
{
    string s,t;
    cin >> s >> t;
    int salph[26];
    int talph[26];
    sort(s.begin(), s.end(), greater<string>());
    sort(t.begin(), t.end(), greater<string>());
    rep(i, (s.size() - 1))
    {
        rep(j, 26)
        {
            if(s[i] == '@')
            {

            }
        }
    }
    return 0;
}
