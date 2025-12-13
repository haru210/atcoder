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

pint def[4] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

# pragma GCC target("avx2")
# pragma GCC optimize("O3")
# pragma GCC optimize("unroll-loops")

int main()
{
    int n, m;
    cin >> n >> m;
    int r[m], c[m];
    set<pint> ng;
    ll ans = 0;
    rep(i, m)
    {
        cin >> r[i] >> c[i];
    }
    rep(i, m)
    {
        bool ok = true;
        rep(j, 4)
        {
            if(ng.find({r[i] + def[j].first, c[i] + def[j].second}) != ng.end()) ok = false;
        }
        if(ok)
        {
            rep(j, 4)
            {
                ng.insert({r[i] + def[j].first, c[i] + def[j].second});
            }
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}