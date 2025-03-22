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
    int h[n];
    rep(i, n) cin >> h[i];
    int dp[n][n];
    rep(i, n) rep(j, n) dp[i][j] = 1;
    int ans = 1;
    rep(i, n)
    {
        rep2(j, n - 1)
        {
            if(i - j < 0) dp[i][j] = 1;
            else if(h[i] == h[i - j]) dp[i][j] = dp[i - j][j] + 1;
            ans = max(ans, dp[i][j]);
        }
    } 
    cout << ans << endl;
    return 0;
}