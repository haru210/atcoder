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
const long long l_inf = 1LL << 60;

int main()
{
    ll h, w, c;
    cin >> h >> w >> c;
    ll a[h+1][w+1];
    ll ra[h+1][w+1];
    ll min_cost = l_inf;
    rep2(i, h)
    {
        rep2(j, w) 
        {
            cin >> a[i][j];
            ra[i][w - (j - 1)] = a[i][j];
        }
    }
    ll dp[h+1][w+1] = {};
    ll rdp[h+1][w+1] = {};
    rep(i, h + 1)
    {
        dp[i][0] = l_inf;
        rdp[i][0] = l_inf;
    }
    rep(i, w + 1)
    {
        dp[0][i] = l_inf;
        rdp[0][i] = l_inf;
    }
    rep2(i, h)
    {
        rep2(j, w)
        {
            ll ans = l_inf;
            ll rans = l_inf;
            dp[i][j] = min((ll)a[i][j], min(dp[i - 1][j] + c, dp[i][j - 1] + c));
            rdp[i][j] = min((ll)ra[i][j], min(rdp[i - 1][j] + c, rdp[i][j - 1] + c));
            ans = min(dp[i - 1][j] + c + a[i][j], dp[i][j - 1] + c + a[i][j]);
            rans = min(rdp[i - 1][j] + c + ra[i][j], rdp[i][j - 1] + c + ra[i][j]);
            min_cost = min(min_cost, min(ans, rans));
        }
    }
    cout << min_cost << endl;
    return 0;
}