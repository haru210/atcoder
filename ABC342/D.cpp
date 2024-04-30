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

void prime_factorize(vector<pll>& res, ll a)
{
    for(ll i = 2; i * i <= a;i++)
    {
        if(a % i != 0) continue;
        ll ex = 0;
        while(a % i == 0)
        {
            a /= i;
            ex++;
        }
        if(ex % 2 != 0) res.push_back(make_pair(i,1));
    }
    if(a != 1) res.push_back(make_pair(a,1));
}

int main()
{
    ll n;
    ll ans = 0;
    cin >> n;
    ll a[n];
    rep(i,n) cin >> a[i];
    ll z_cnt = 0;
    rep(i,n)
    {
        if(a[i] == 0)
        {
            z_cnt++;
            ans += (n-z_cnt);
        }
    }
    vector<vector<pll>> pfres(n);
    map<vector<pll>,ll> equal_cnt;
    rep(i,n)
    {
        if(a[i] == 0) continue;
        prime_factorize(pfres[i], a[i]);
        equal_cnt[pfres[i]]++;
    }
    for(auto& [key, val]: equal_cnt)
    {
        if(val >= 2)
        {
            ans += (val * (val-1)) / 2;
        }
    }
    cout << ans << endl;
    return 0;
}