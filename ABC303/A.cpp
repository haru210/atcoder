#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n;
    string s, t;
    bool key = true;
    cin >> n >> s >> t;
    rep(i, n)
    {
        if(s[i] == t[i]) continue;
        else if((s[i] == '1' && t[i] == 'l') ||(s[i] == 'l' && t[i] == '1') || (s[i] == '0' && t[i] == 'o') || (s[i] == 'o' || t[i] == '0'))
        {
            continue;
        }
        else key = false;
    }
    if(key) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}