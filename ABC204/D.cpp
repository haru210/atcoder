#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << " No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << " NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
bool dp[105][100005] = {false};
//dp[i][j] i番目までの料理をj分で終わらせられるか
int main()
{
    int n;
    int sum = 0;
    cin >> n;
    int t[n+1];
    for(int i = 1; i <= n; i++)
    {
        cin >> t[i];
        sum += t[i];
    }
    dp[0][0] = true;
    for(int i = 1; i <= n; i++)
    {
        dp[i][0] = true;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j =1; j <= sum; j++)
        {
            if(j-t[i] >= 0){
                //選ぶ
                if(dp[i-1][j-t[i]])
                {
                    dp[i][j] = true;
                }
                //選ばない
                if(dp[i-1][j])
                {
                    dp[i][j] = true;
                }
            }
        }
    }
    int ans = inf;
    for(int i = 0; i <= sum; i++)
    {
        int tmp;
        if(dp[n][i])
        {
            tmp = max(i,sum - i);
        }
        ans = min(ans,tmp);
    }
    cout << ans << endl;
    return 0;
}