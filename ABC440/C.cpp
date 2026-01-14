#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    int t;
    cin >> t;
    rep(cs, t)
    {
        int n, w;
        cin >> n >> w;
        ll w_mod[2 * w] = {};
        rep(i, n)
        {
            ll c;
            cin >> c;
            w_mod[(i % (2 * w))] += c;
        }
        ll cost = 0;
        rep(i, w)
        {
            cost += w_mod[i];
        }
        ll ans = cost;
        rep2(i, (2 * w) - 1)
        {
            int left = i - 1;
            int right = (i + w - 1) % (2 * w);
            cost = cost - w_mod[left] + w_mod[right];
            ans = min(ans, cost);
        }
        cout << ans << endl;
    }
    return 0;
}