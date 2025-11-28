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

// 全部飲むことにしてよい
bool plcomp(const pll& a, const pll& b)
{
    int defa = a.first - a.second;
    int defb = b.first - b.second;
    if(defa == defb)
    {
        return (a.first< b.first);
    }
    else return (defa < defb);
}

int main()
{
    ll n, m;
    cin >> n >> m;
    pll exc[m];
    rep(i, m)
    {
        cin >> exc[i].first >> exc[i].second;
    }
    sort(exc, exc + m, plcomp);
    ll ans = 0;
    rep(i, m)
    {
        ll cnt = (n - exc[i].first + 1) / (exc[i].first - exc[i].second);
        if(cnt == 0 && n >= exc[i].first) cnt = 1; 
        if(cnt < 0) cnt = 0;
        ans += cnt;
        n -= cnt * (exc[i].first - exc[i].second);
    }
    cout << ans << endl;
    return 0;
}