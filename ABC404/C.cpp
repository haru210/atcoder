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
vector<bool> seen;

void dfs(vector<vector<int>>& g, int v)
{
    seen[v] = true;
    for(auto& nv : g[v])
    {
        if(!seen[nv])
        {
            dfs(g, nv);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    seen.resize(n, false);
    vector<vector<int>> g(n);
    bool ans = true;
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if(m != n)
    {
        cout << "No\n";
        return 0;
    }
    rep(i, n)
    {
        if(g[i].size() != 2)
        {
           ans = false;
        }
    }
    dfs(g, 0);
    rep(i, n)
    {
        if(!seen[i]) 
        {
            ans = false;
        }
    }
    YesNo(ans);
    return 0;
}