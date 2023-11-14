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
    int n;
    cin >> n;
    int a[n+1], b[n+1], c[n+1];
    rep2(i,n)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    int dp[n+1][3] = {}; //dp[i][j]を、最後にした行動がjのときのi日目までの幸福度の最大値
    //j = 0, 1, 2 
    rep2(i,n)
    {
        dp[i][0] = max(max(dp[i-1][1] + a[i], dp[i-1][2] + a[i]), dp[i][0]);
        dp[i][1] = max(max(dp[i-1][0] + b[i], dp[i-1][2] + b[i]), dp[i][1]);
        dp[i][2] = max(max(dp[i-1][0] + c[i], dp[i-1][1] + c[i]), dp[i][2]);
    }
    int ans = max(dp[n][0], dp[n][1]);
    ans = max(ans, dp[n][2]);
    cout << ans << endl;
    return 0;
}