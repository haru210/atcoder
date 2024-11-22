#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

int main()
{
    string s;
    cin >> s;
    bool ok = true;
    if(s.size() % 2 != 0) ok = false;
    char cnt[26] = {};
    rep(i, s.size())
    {
        cnt[(int)s[i] - 'a']++;
    } 
    for(int i = 0; i < s.size() - 1; i += 2)
    {
        if(s[i] != s[i + 1]) ok = false;
    }

    rep(i, 26)
    {
        if(cnt[i] != 0 && cnt[i] != 2) ok = false;
    }
    YesNo(ok);
    return 0;
}