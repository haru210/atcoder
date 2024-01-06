#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;
using graph = vector<vector<int>>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

#pragma GCC target("avx")
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")

bool seen[200100] = {};
int a[200100] = {};
int cnt[200100] = {}; 
int ans = 0;
int n,m;
void dfs(graph& g, int v, int score)
{
    seen[v] = true;
    if(cnt[a[v]] == 0)
    {
        score++;
    }
    cnt[a[v]]++;
    if(v == (n - 1))
    {
        ans = max(ans, score);
    } 
    int next_v;

    rep(i,g[v].size())
    {
        next_v = g[v][i];
        if(seen[next_v] == false && a[v] <= a[next_v])
        {
            dfs(g,next_v, score);
            cnt[a[next_v]]--;
        }
    }
    seen[v] = false;
}
int main()
{

    cin >> n >> m;
    graph g(n);
    rep(i,n) cin >> a[i];
    rep(i,m)
    {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(g, 0, 0);
    cout << ans << endl;
    return 0;
}