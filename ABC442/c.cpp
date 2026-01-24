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

map<pll, ll> memo;
ll nCr(ll n, ll r)
{
    if (n == r) return 1;
    else if (r == 0) return 1;
    else if (r == 1) return n;
    else
    {
        if (memo[{n, r}] == 0)
        {
            ll num = (nCr(n - 1, r - 1) +  nCr(n - 1, r));
            memo[{n, r}] = num;
            return num;
        }
        else
        {
            return memo[{n, r}];
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> r(n);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        r[a].push_back(b);
        r[b].push_back(a);
    }
    rep(i, n)
    {
        ll res_cnt =  n - 1 - r[i].size();
        if (res_cnt < 3) cout << 0 << ' ';
        else
        {
            cout << nCr(res_cnt, 3) << ' ';
        }
    }
    return 0;
}
