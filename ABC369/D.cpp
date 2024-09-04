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

int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    rep2(i, n) cin >> a[i];
    ll dp[n + 1][2] = {}; //dp[i][j] = i番目までで(倒した数 mod 2)=jの時の経験値の最大値
    dp[0][1] = -inf;
    rep2(i, n)
    {
        //偶数体になる場合
        dp[i][0] = max(dp[i - 1][1] + 2 * a[i], dp[i - 1][0]);
        //奇数体になる場合
        dp[i][1] = max(dp[i - 1][0] + a[i], dp[i - 1][1]);
    }
    cout << max(dp[n][0] , dp[n][1]) << endl;
    return 0;
}