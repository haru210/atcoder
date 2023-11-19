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

int dp[1005][1005]; //i番目までのビルで、j番目が最後となるときの最長の長さ
int main()
{
    int n;
    cin >> n;
    int a[n+1];
    a[0] = 0;
    rep2(i,n) cin >> a[i];
    rep(i,n+1) rep(j,n+1) dp[i][j] = 0;
    int ans = -1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(a[i+1] > a[j])
            {
                dp[i+1][i+1] = max(dp[i+1][i+1], dp[i][j]+1);
            }
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        }
    }
    rep2(i,n)
    {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}