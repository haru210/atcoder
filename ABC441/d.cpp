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

set<int> ans;
int s, t, l;
void dfs(vector<vector<pint>>& g, int v, int depth, ll cost)
{
    if (depth == l)
    {
        if (s <= cost && cost <= t)
        {
            ans.insert(v + 1);
        }
        return;
    }
    for (auto nv : g[v])
    {
        dfs(g, nv.first, depth + 1, cost + nv.second);
    }
}

int main()
{
    //出次数4とL<=10に意味がありそう
    //頂点1から移動する方法は4^L通り
    //全探索できるのでは？
    int n, m;
    cin >> n >> m >> l >> s >> t;
    vector<vector<pint>> g(n); //頂点、コスト
    rep(i, m)
    {
        int u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        g[u].push_back({v, c});
    }
    dfs(g, 0, 0, 0);
    for (auto & val : ans)
    {
        cout << val << ' ';
    }
    if (ans.size() == 0) cout << endl;
    return 0;
}
