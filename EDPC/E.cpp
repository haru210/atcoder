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
    //w <= 10^9よりdp[i][w]は使えない
    //dp[i][v] := i番目までで価値がちょうどvになるように選ぶ時のwの最小値
    int n,w;
    cin >> n >> w;
    ll we[n+1], va[n+1];
    int va_max = 0;
    rep2(i,n)
    {
        cin >> we[i] >> va[i];
        va_max += va[i];
    }
    ll dp[n+1][va_max+1] = {};
    rep(i,n) rep(j,va_max + 1) dp[i][j] = -1;
    dp[0][0] = 0;
    rep2(i,n)
    {
        rep(j,va_max + 1)
        {
            bool ch = false; //選べないときtrue
            // dp[i][j] = dp[i-1][j] (選ばないとき)
            // dp[i][j] = min(dp[i-1][j - va[i]] + weight, dp[i-1][j])
            if(j - va[i] < 0) ch = true;
            if(!ch)
            {
                if(dp[i-1][j - va[i]] == -1) ch = true;
            }
            if(ch)
            {
               dp[i][j] = dp[i-1][j]; 
            }
            else
            {
                if(dp[i-1][j] == -1) dp[i][j] = dp[i-1][j - va[i]] + we[i];
                else dp[i][j] = min(dp[i-1][j - va[i]] + we[i], dp[i-1][j]);
            }
        }
    }
    for(int i = va_max; i > -1; i--)
    {
        if(dp[n][i] != -1)
        {
            if(dp[n][i] <= w)
            {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}