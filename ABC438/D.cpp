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
    int n;
    cin >> n;
    ll a[n + 1];
    ll b[n + 1];
    ll c[n + 1];
    rep2(i, n) cin >> a[i];
    rep2(i, n) cin >> b[i];
    rep2(i, n) cin >> c[i];
    ll dp[n + 1][3] = {};
    dp[0][1] = -inf;
    dp[0][2] = -inf;
    dp[1][2] = -inf;
    rep2(i, n)
    {
        dp[i][0] = dp[i - 1][0] + a[i];
        if (i >= 2)dp[i][1] = max(dp[i - 1][1] + b[i], dp[i - 1][0] + b[i]); //胴を継続、胴に変える
        if (i >= 3)dp[i][2] = max(dp[i - 1][2] + c[i], dp[i - 1][1] + c[i]);
    }
    cout << dp[n][2] << endl;
    return 0;
}
