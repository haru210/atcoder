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

ll sum[1005][1005] = {};
ll n,q;

ll calc_sum(ll i,ll j)
{
    //(1,1)~(i,j)までの和を計算する
    ll a,b,c;
    ll ans = 0;
    a = (i / n) * (j / n);
    b = sum[n][j % n];
    c = sum[i % n][n];
    ans += a * sum[n][n];
    ans += b * (i / n);
    ans += c * (j / n);
    ans += sum[i % n][j % n];
    return ans;
}
int main()
{
    cin >> n >> q;
    char p[n+1][n+1];
    rep2(i,n) rep2(j,n) cin >> p[i][j];
    rep2(i,n)
    {
        rep2(j,n)
        {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            if(p[i][j] == 'B') sum[i][j]++;
        }
    }
    rep(i,q)
    {
        ll i1,j1,i2,j2;
        cin >> i1 >> j1 >> i2 >> j2;
        i1++;
        j1++;
        i2++;
        j2++;
        ll ans = 0;
        ans = calc_sum(i2,j2) - calc_sum(i2, (j1-1)) - calc_sum((i1-1), j2) + calc_sum((i1-1), (j1-1));
        cout << ans << endl; 
    }
    return 0;
}