#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 1000000000;
const long long l_inf = 9223372036854775807;

int main()
{
    int n, m;
    cin >> n >> m;
    int l[400][400];
    rep(i, n)
    {
        rep(j, n)
        {
            l[i][j] = inf;
            if(i == j) l[i][j] = 0;
        }
    }
    rep(i, m)
    {
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        l[a][b] = c;
    }
    ll ans = 0;
    rep(i, n)
    {
        rep(j, n)
        {
            rep(k, n)
            {
                l[j][k] = min(l[j][k], l[j][i] + l[i][k]);
                if(l[j][k] < inf) ans += l[j][k];
            }
        }
    }
    cout << ans << endl;
    return 0;
}