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
    //dp[S][i] := 問題集合Sを解いている時、残金i円でこれから得られる得点の期待値
    int n, x;
    cin >> n >> x;
    int s[n], c[n];
    long double p[n];
    rep(i, n) cin >> s[i] >> c[i] >> p[i];
    rep(i, n) p[i] /= 100; 
    long double dp[1 << n][x + 1] = {};
    rep(i, x + 1) //残金がi円の時
    {
        rep(j, 1 << n) //問題集合jに正解してる時
        {
            rep(k, n) //問題kに提出する
            {
                if((j | (1 << k)) == j) continue; //既にkを解いている時
                if(i - c[k] < 0) continue;//問題kを解ける残金が残ってない場合
                long double tmp = p[k] * (dp[j | (1 << k)][i - c[k]] + s[k]) + ((1 - p[k]) * dp[j][i - c[k]]);
                dp[j][i] = max(tmp, dp[j][i]);
            }
        }
    }
    cout << setprecision(10);
    cout << dp[0][x] << endl;
    return 0;
}