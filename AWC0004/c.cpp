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
    ll h[n];
    rep(i, n) cin >> h[i];
    sort(h, h + n);
    ll ans = l_inf;
    ll tmp = 0;
    rep(i, n)
    {
        if (i == 0) tmp += abs(h[i]);
        else tmp += abs(h[i] - h[i - 1]);
    }
    tmp += abs(h[n - 1]);
    ans = min(ans, tmp);
    sort(h, h + n, greater<ll>());
    tmp = 0;
    rep(i, n)
    {
        if (i == 0) tmp += abs(h[i]);
        else tmp += abs(h[i] - h[i - 1]);
    }
    tmp += abs(h[n - 1]);
    ans = min(ans, tmp);
    cout << ans << endl;
    return 0;
}
