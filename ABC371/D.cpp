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
    //累積和を二分探索
    int n;
    cin >> n;
    ll x[n + 1], p[n + 1];
    rep2(i, n) cin >> x[i];
    rep2(i, n) cin >> p[i];
    x[0] = -inf;
    p[0] = 0;
    ll sum[n + 1];
    sum[0] = 0;
    rep2(i, n)
    {
        sum[i] = sum[i - 1] + p[i];
    }
    int q;
    cin >> q;
    rep(i, q)
    {
        int l, r;
        cin >> l >> r;
        int ln = lower_bound(x, x + n + 1, l) - x;
        ln--;
        int rn = upper_bound(x, x + n + 1, r) - x;
        rn--;
        cout << sum[rn] - sum[ln] << endl;
    }
    return 0;
}