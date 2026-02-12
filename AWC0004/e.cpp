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

// r[i] - l[i - 1] = k
// r[i] = k + l[i - 1]
int main()
{
    int n, k;
    cin >> n >> k;
    ll a[n + 1];
    rep2(i, n) cin >> a[i];
    ll sum[n + 1];
    sum[0] = 0;
    rep2(i, n) sum[i] = sum[i - 1] + a[i];
    map<ll, int> num;
    ll ans = 0;
    for (int i = n; i >= 0; i--)
    {
        num[sum[i]]++;
        ans += num[k + sum[i - 1]];
    }
    cout << ans << endl;
    return 0;
}
