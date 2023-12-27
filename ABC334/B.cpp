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
    ll a,m,l,r;
    cin >> a >> m >> l >> r;
    ll ax = a % m;
    if(ax <= 0) ax += m;
    ll dist = r - l;
    ll tree = (dist / m);
    ll r_l = l + (tree * m);
    ll l_mod = (l % m);
    if(l_mod <= 0) l_mod += m;
    ll r_mod = (r % m);
    if(r_mod <= 0) r_mod += m;
    if(l_mod <= r_mod)
    {
        if(l_mod <= ax && ax <= r_mod) tree++;
    }
    else
    {
        if((l_mod <= ax && ax <= m) || (ax >= 0 && ax <= r_mod)) tree++;
    }
    cout << tree << endl;
    return 0;
}