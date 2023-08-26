#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << " No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << " NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

void dfs(vector<vector<pair<int,int>>>& g, int v);

bool seen[15] = {false};
int cur = 0;
int ans = 0;
int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> g(n);
    rep(i,m)
    {
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].push_back(make_pair(b,c));
        g[b].push_back(make_pair(a,c));
    }
    rep(i,n)
    {
        cur = 0;
        dfs(g,i);
    }
    cout << ans << endl;
    return 0;
}

void dfs(vector<vector<pair<int,int>>>& g, int v)
{
    seen[v] = true;
    int next_v;

    for(int i = 0; i < g[v].size(); i++)
    {
        next_v = g[v][i].first;
        if(seen[next_v] == false)
        {
            cur += g[v][i].second;
            ans = max(ans,cur);
            dfs(g,next_v);
            seen[next_v] = false;
            cur -= g[v][i].second;
        }
    }
    seen[v] = false;
}
