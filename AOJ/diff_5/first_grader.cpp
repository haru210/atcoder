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
    //全パターンを確かめることは出来ない
    //後ろから決めていくことで前部分が何パターンできるかに帰着できる?
    //現れる数字が0~20なら0~20それぞれについて組み合わせの数を足し合わせればよい？
    int n;
    cin >> n;
    int a[n];
    rep(i,n) cin >> a[i];
    ll dp[n][21] = {};
    dp[0][a[0]] = 1;
    rep2(i,n-2)
    {
        //全数字から足した時、引いたときの遷移を行う
        rep(j,21)
        {
            if(j + a[i] <= 20 && dp[i-1][j] != 0)
            {
                dp[i][j+a[i]] += dp[i-1][j];
            }
            if(j - a[i] >= 0 && dp[i-1][j] != 0)
            {
                dp[i][j-a[i]] += dp[i-1][j];
            }
        }
    }
    cout << dp[n-2][a[n-1]] << endl;
    return 0;
}