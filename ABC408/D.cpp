#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 1000000000;
const long long l_inf = 9223372036854775807;

int main()
{
    //消し続ける->繋ぎ続ける->消し続けるになるはず
    //フェーズを管理してdp
    int t;
    cin >> t;
    rep(i, t)
    {
        int n;
        string s;
        cin >> n >> s;
        int dp[n][3] = {};
        bool canphase2 = false; //1が出てこないと繋ぐフェーズに行けない
        rep(j, n)
        {
           // cout << "now\n";
            if(s[j] == '0')
            {
                if(j != 0) dp[j][0] = dp[j - 1][0];
                if(canphase2) dp[j][1] = min(dp[j - 1][1] + 1, dp[j - 1][0] + 1); //全0の場合0から繋ぎ始めることがある 
                else dp[j][1] = dp[j - 1][0] + 1;
                if(canphase2) dp[j][2] = min(dp[j - 1][2], dp[j - 1][1]); //直前まで繋いでて、消し始めるはあり得る
                else dp[j][2] = inf;
            }
            else
            {
                if(j != 0) dp[j][0] = dp[j - 1][0] + 1;
                else dp[j][0] = 1;
                if(j != 0) dp[j][1] = min(dp[j - 1][0], dp[j - 1][1]); //ここから区間を始めるor区間を継続
                if(canphase2) dp[j][2] = min(dp[j - 1][1] + 1, dp[j - 1][2] + 1);//1回1が出た次から起こり得るようにしたい
                else dp[j][2] = inf;
                if(!canphase2) canphase2 = true;
            }
        }
     /*   rep(i, n)
        {
            cout << dp[i][0] << ' '<<dp[i][1] << ' ' << dp[i][2] << endl;
        } */
        cout << min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]) << endl; //フェーズ0だと区間が無いので
    }
    return 0;
}