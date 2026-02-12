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
    ll n, t;
    cin >> n >> t;
    ll a[n], b[n];
    rep(i, n)
    {
        cin >> a[i] >> b[i];
    }
    rep(i, n)
    {
        a[i] -= b[i] * t;
        if (a[i] < 0) a[i] = 0;
    }
    ll sum = 0;
    rep(i, n)
    {
        sum += a[i];
    }
    cout << sum << endl;
    return 0;
}
