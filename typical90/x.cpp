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
    ll n, k;
    cin >> n >> k;
    ll a[n], b[n];
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    ll dis = 0;
    rep(i, n)
    {
        dis += abs(b[i] - a[i]);
    }
    bool ok;
    if(dis > k) ok = false;
    else if(abs(k - dis) % 2 == 0) ok = true;
    else ok = false;
    YesNo(ok);
    return 0;
}