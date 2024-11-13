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

ll ntom(ll n, ll m) //nから数字m個の自然数の和
{
    if(n == m - 1) return n * (n + 1) / 2;
    else return (n * (n + 1) / 2) - ((n - m) * (n - m + 1) / 2);
}

int main()
{
    ll n, m;
    cin >> n >> m;
    pll x[m];
    rep(i, m) cin >> x[i].first;
    rep(i, m) cin >> x[i].second;
    sort(x, x + m);
    ll ans = 0;
    bool impossible = false;
    if(x[0].first != 1) impossible = true;
    rep(i, m)
    {
        ll span;
        if(i != m - 1) span = x[i+1].first - x[i].first;
        else span = n - x[i].first + 1;
        if(x[i].second < span)
        {
            impossible = true;
            break;
        }
        ll cnt = ntom(x[i].second - 1, span);
        ans += cnt;
        if(i != m - 1) x[i + 1].second += x[i].second - span;
        else if(x[i].second - span != 0) impossible = true;
    }
    if(impossible) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}