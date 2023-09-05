#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for(int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << " No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << " NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n;
    cin >> n;
    int line[n+1][n+1];
    ll dp[1 << n];
    for(int i = 1; i < n; i++) for(int j = i+1; j <= n; j++)
    {
        cin >> line[i][j];
        line[j][i] = line[i][j];
    }
    rep(i,(1<<n))
    {
        dp[i] = 0;
    }
    dp[0] = 0;
    rep(i,(1 << n)-1)
    {
        for(int j = 1; j <= n;j++)
        {
            for(int k = j+1; k <= n; k++)
            {
                if((((1<<(j-1)) & i) == 0) && (((1<<(k-1)) & i) == 0))
                {
                    int next = i | 1 << (j-1) | 1<< (k-1);
                    dp[next] = max(dp[next],dp[i] + line[j][k]);
                }
            }
        }
    }
    cout << dp[(1<<n)-1] << endl;
    return 0;
}