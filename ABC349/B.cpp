#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    bool ok = true;
    string s;
    cin >> s;
    int cnt[26] = {};
    rep(i,s.size())
    {
        cnt[(int)(s[i] - 'a')]++;
    }
    int cnt_cnt[200] = {};
    rep(i,26)
    {
        cnt_cnt[cnt[i]]++;
    }
    rep(i,200)
    {
        if(i == 0) continue;
        if(!(cnt_cnt[i] == 0 || cnt_cnt[i] == 2)) ok = false;
    }
    YesNo(ok);
    return 0;
}