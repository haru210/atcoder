#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

# pragma GCC target("avx2")
# pragma GCC optimize("O3")
# pragma GCC optimize("unroll-loops")

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int n, m;
vector<vector<pint>> g;
bool seen[1000][1000] = {};
int ans = inf;

void dfs(int v, int xorsum)
{
    if(v == n - 1)
    {
        ans = min(ans, xorsum);
    }
    for(pint nv: g[v])
    {
        if(!seen[v][nv.first])
        {
            seen[v][nv.first] = true;
            dfs(nv.first, xorsum ^ nv.second);
            seen[v][nv.first] = false;
        }
    }
}

int main()
{
    //XOR演算は二回行うと元に戻る
    //一つの辺は1回しか通らないと考えても良い？
    cin >> n >> m;
    g.resize(n);
    rep(i, m)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        g[a].push_back({b, w});
    }
    dfs(0, 0);
    if(ans == inf) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}