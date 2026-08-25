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
    ll n, m, k;
    cin >> n >> m >> k;
    ll a[n];
    bool eaten[n] = {};
    rep(i, n) cin >> a[i];
    ll ncal = 0;
    rep(i, n)
    {
        if (i < m)
        {
            if (ncal + a[i] <= k)
            {
                ncal += a[i];
                eaten[i] = true;
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
        else
        {
            if (eaten[i - m])ncal -= a[i - m];
            if (ncal + a[i] <= k)
            {
                ncal += a[i];
                eaten[i] = true;
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
    }
    return 0;
}
