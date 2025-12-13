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

int dfs(vector<vector<int>>& g, vector<int>& seen, int v, int depth)
{
    seen[v] = true;
    for(auto& nv: g[v])
    {
        if(!seen[nv])
        {
            depth = dfs(g, seen, nv, depth + 1);
        }
    }
    return depth;
}

int main()
{
    int n;
    cin >> n;
    int p[n];
    rep(i, n)
    {
        cin >> p[i];
        p[i]--;
    }
    vector<vector<int>> g(n);
    vector<int> seen(n, false);
    rep(i, n)
    {
        g[i].push_back(p[i]);
    }
    ll ans = 0;
    rep(i, n)
    {
        if(!seen[i])
        {
            int vcnt = dfs(g, seen, i, 1);
            ans += (ll)vcnt * (vcnt - 1) / 2;
        }
    }
    cout << ans << endl;
    return 0;
}