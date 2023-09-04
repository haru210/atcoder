#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for(int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << " No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << " NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int dp[105][1024];
int main()
{
    int n,m;
    cin >> n >> m;
    int a[m+10][n+10];
    rep2(i,m) rep2(j,n) cin >> a[i][j];
    rep(i,m+1) rep(j, (1 << n)) dp[i][j] = inf;
    dp[0][0] = 0;
    rep(i,m)
    {
        rep(j,(1 << n))
        {
            if(dp[i][j] == inf) continue;
            //選ばない場合
            dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
            //選ぶ場合
            //選んだ時のSとクーポンの和集合を求める
            //クーポンを整数表現にする
            int v = 0;
            v |= j;
            for(int k = 1; k <= n; k++)
            {
                if(a[i+1][k] == 1)
                 {
                    v |=  (1 << (k-1));
                }
            }
            dp[i+1][v] = min(dp[i+1][v],dp[i][j] + 1);
        }
    }
    if(dp[m][(1 << n) - 1] == inf) cout << "-1" << endl;
    else cout << dp[m][(1 << n) - 1] << endl; 
    return 0;
}