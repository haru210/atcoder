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
    ll n;
    cin >> n;
    ll a[n];
    ll s[n-1],t[n-1];
    rep(i,n) cin >> a[i];
    rep(i,n-1) cin >> s[i] >> t[i];
    rep(i,n-1)
    {
        ll cnt = a[i] / s[i];
        a[i+1] += cnt * t[i];
    }
    cout << a[n-1] << endl;
    return 0;
}