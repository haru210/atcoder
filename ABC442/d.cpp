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
    ll a[n + 1];
    rep2(i, n) cin >> a[i];
    ll sum[n + 1];
    sum[0] = 0;
    rep2(i, n)
    {
        sum[i] = sum[i - 1] + a[i];
    }
    rep(q_cnt, q)
    {
        int query;
        cin >> query;
        if (query == 1)
        {
            int x;
            cin >> x;
            sum[x] += a[x + 1] - a[x];
            swap(a[x + 1], a[x]);
        }
        else
        {
            cout << endl;
            int l, r;
            cin >> l >> r;
            cout << sum[r] - sum[l - 1] << endl;
        }
    }
    return 0;
}
