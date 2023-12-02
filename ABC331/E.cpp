#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n,m,l;
    ll ans = 0;
    cin >> n >> m >> l;
    ll a[n];
    pint b[m];
    map<pint, bool> ng;
    rep(i,n) 
    {
        cin >> a[i];
    }
    rep(i,m)
    {
        cin >> b[i].first;
        b[i].second = i;
    }
    rep(i,l)
    {
        int c,d;
        cin >> c >> d;
        c--; d--;
        ng[make_pair(c,d)] = true;
        ng[make_pair(d,c)] = true;
    }
    sort(b,b+m);
    //各主菜からの最大値をO(M)以下で求められれば...
    rep(i,n)
    {
        for(int j = m - 1; j >= 0; j--)
        {
            if(!ng[make_pair(i,b[j].second)])
            {
                if(a[i] + b[j].first > ans) ans = a[i] + b[j].first;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}