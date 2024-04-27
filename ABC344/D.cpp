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

//dp[i][j] = i個目の袋まででj文字目までを埋める最小価格
//dp[n][t.size()]を出力する
int dp[101][101] = {};
int main()
{
    rep(i, 101) rep(j, 101)
    {
        if(j == 0) dp[i][0] = 0; //埋めないことは0円でできるので
        else dp[i][j] = -1;
    }
    string t;
    int n;
    cin >> t >> n;
    vector<vector<string>> s(n+1);
    int a[n+1];
    rep2(i,n)
    {
        cin >> a[i];
        rep2(j, a[i])
        {
            string tmp;
            cin >> tmp;
            s[i].push_back(tmp);
        }
    }
    rep2(i, n)
    {
        //選ばない場合
        rep(j, t.length() + 1)
        {
            dp[i][j] = dp[i-1][j];
        }
        rep(j, a[i])
        {
            //選ぶ場合
            rep2(k, (t.length() - (s[i][j].length() - 1))) //何文字目に入れれそうか
            {
                bool can_insert = true;
                rep2(l, s[i][j].length()) //整合性チェック
                {
                    if(s[i][j][l-1] != t[k + l - 2])
                    {
                        can_insert = false;
                    } 
                }
                if(!can_insert) continue;
                if(dp[i-1][k-1] == -1) continue;
                if(dp[i][k + (s[i][j].length() - 1)] == -1)
                {
                    dp[i][k + (s[i][j].length() - 1)] = dp[i-1][k-1] + 1;
                }
                else
                {
                    dp[i][k + (s[i][j].length() - 1)] = min(dp[i][k + (s[i][j].length() - 1)], dp[i-1][k-1] + 1);
                }
            }
        }
    }
    cout << dp[n][t.length()] << endl;
    return 0;
}