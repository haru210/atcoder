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
// m=1,n=2*10^5のとき10^9を超えるので全パターン数えることはできない
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    rep(i, n) cin >> a[i];
    rep(i, n) a[i] %= m;
    vector<vector<int>> mm(m);
    ll sum = 0;
    ll ans = 0;
    mm[0].push_back(0);
    rep2(i, n)
    {
        sum += a[i - 1];
        sum %= m;
        mm[sum].push_back(i);
    }
    rep(i, n - 1)
    {
        sum += a[i];
        sum %= m;
        mm[sum].push_back(i + n + 1);
    }
    rep(i, m)
    {
        rep(j, mm[i].size() - 1)
        {
            if(mm[i][j] >= n) break;
            int id = lower_bound(mm[i].begin() + (j + 1), mm[i].end(), mm[i][j] + n) - mm[i].begin();
            id--;
            id -= j;
            if(id >= 0) ans += id;
        }
    }
    cout << ans << endl;
    return 0;
}