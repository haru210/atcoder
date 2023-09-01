#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << " No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << " NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

void dfs(graph& g,int v,int first);

bool seen[2005] = {false};
map<pair<int,int>,bool> p;
ll ans = 0;

int main()
{
    int n,m;
    cin >> n >> m;
    graph g(n);
    rep(i,m)
    {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
    }
    rep(i,n)
    {
        rep(i,n)
        {
            seen[i] = false;
        }
        if(p[make_pair(i,i)] == false)
        {
            p[make_pair(i,i)] = true;
            ans++;
        }
        dfs(g,i,i);
    }
    cout << ans << endl;
    return 0;
}

void dfs(graph& g,int v,int first)
{
    seen[v] = true;
    int next_v;
    rep(i,g[v].size())
    {
        next_v = g[v][i];
        if(p[make_pair(first,next_v)] == false)
        {
            ans++;
            p[make_pair(first,next_v)] = true;
        }
        if(seen[next_v] == false)
        {
            dfs(g,next_v,first);
        }
    }
}