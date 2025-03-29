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

ll MOD = 1000000007;
int main()
{
    //dp[i][j] := i文字目でchokudaiのj文字目まで線を引く方法
    string s;
    string target = "chokudai";
    cin >> s;
    ll dp[s.size() + 1][target.size() + 1];
    rep(i, target.size() + 1) dp[0][i] = 0;
    dp[0][0] = 1;
    rep2(i, s.size())
    {
        rep(j, target.size() + 1)
        {
            dp[i][j] = dp[i - 1][j];
            dp[i][j] %= MOD;
            //その文字に線を引ける場合
            if(s[i - 1] == target[j - 1])
            {
                dp[i][j] += dp[i - 1][j - 1];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[s.size()][target.size()] << endl;
    return 0;
}