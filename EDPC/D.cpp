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
ll dp[101][100001] = {0};
int main()
{
    int n,w;
    cin >> n >> w;
    int weight[n+1], value[n+1];
    rep2(i,n)
    {
        cin >> weight[i] >> value[i];
    }
    rep2(i,n)
    {
        rep(j, w+1)
        {
            /*dpの遷移
                dp[i][j] = max(dp[i-1][j - weight[i]] + value[i], dp[i-1][j]) 選べるとき
                dp[i][j] = max(dp[i-1][j]) 選べないとき
            */
            if(j - weight[i] >= 0)
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - weight[i]] + value[i]);
            }
            else 
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][w] << endl;
    return 0;
}