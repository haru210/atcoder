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
    ll n, k ,x;
    cin >> n >> k >> x;
    ll a[n];
    rep(i, n) cin >> a[i];
    //大きい奴から飲んでいくのが良さそうで、上からn-k個が水だった時が最悪ケース
    sort(a, a + n, greater<ll>());
    ll sum = 0;
    int ans = -1;
    for (int i = n - k; i < n; i++)
    {
        sum += a[i];
        if (sum >= x)
        {
            ans = i + 1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
