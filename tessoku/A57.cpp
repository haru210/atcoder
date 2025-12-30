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
    int n, q;
    cin >> n >> q;
    int a[n + 1];
    int dp[32][n + 1];
    rep2(i, n) cin >> a[i];
    rep2(i, n)
    {
        dp[0][i] = a[i];
    }
    rep2(i, 31)
    {
        rep2(j, n)
        {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
    rep(i, q)
    {
        int x, y;
        cin >> x >> y;
        int pos = x;
        rep(j, 30)
        {
            if ((y & (1 << j)) != 0) pos = dp[j][pos];
        }
        cout << pos << endl;
    }
    return 0;
}