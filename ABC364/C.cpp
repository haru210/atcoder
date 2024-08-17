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
    ll n, x, y;
    cin >> n >> x >> y;
    ll a[n];
    ll b[n];
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    sort(a, a + n, greater<ll>());
    sort(b, b + n, greater<ll>());
    ll sw = 0;
    ll sa = 0;
    ll sac = 0;
    ll swc = 0;
    rep(i, n)
    {
        sw += a[i];
        if(sw > x)
        {
            swc = i + 1;
            break;
        } 
    }
    if(swc == 0) swc = n;
    rep(i, n)
    {
        sa += b[i];
        if(sa > y) 
        {
            sac = i + 1;
            break;
        }
    }
    if(sac == 0) sac = n;
    cout << min(swc, sac) << endl;
    return 0;
}