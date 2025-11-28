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
    int n, m;
    cin >> n >> m;
    ll a[n];
    rep(i, n) cin >> a[i];
    ll dig10_mod[12];
    ll dig10_tmp = 1;
    rep2(i, 11)
    {
        dig10_mod[i] = dig10_tmp % m;
        dig10_tmp *= 10;
    }
    map<pll, ll> dig_mod;
    rep(i, n)
    {
        string tmp = to_string(a[i]);
        ll dig = tmp.size();
        a[i] %= m;
        dig_mod[{dig, a[i]}]++;
    }
    ll ans = 0;
    rep(i, n)
    {
        rep2(j, 10)
        {
            ll i_mod = (a[i] * dig10_mod[j + 1] ) % m;
            ll rest = m - i_mod;
            if(rest == m) rest = 0;
            ans += dig_mod[{j, rest}];
        }
    }
    cout << ans << endl;
    return 0;
}