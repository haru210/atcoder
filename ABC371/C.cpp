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
    int n, mg, mh;
    cin >> n >> mg;
    bool g[n][n] = {};
    bool h[n][n] = {};
    int money[n][n] = {};
    rep(i, mg)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u][v] = true;
        g[v][u] = true;
    }
    cin >> mh;
    rep(i, mh)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        h[a][b] = true;
        h[b][a] = true;
    }
    rep(i, n - 1)
    {
        for(int j = i + 1; j < n; j++)
        {
            cin >> money[i][j];
        }
    }
    int ho[n];
    rep(i, n) ho[i] = i;
    int ans = inf;
    do
    {
        int num = 0;
        bool ok = true;
        rep(i, n)
        {
            rep(j, n)
            {
                if(i >= j) continue;
                if(g[i][j] != h[ho[i]][ho[j]])
                {
                    int ii, jj;
                    jj = max(ho[i], ho[j]);
                    ii = min(ho[i], ho[j]);
                    num += money[ii][jj];
                }
            }
        }
        ans = min(ans, num);
    }while(next_permutation(ho, ho + n));
    cout << ans << endl;
    return 0;
}