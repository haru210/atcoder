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

//木なので、頂点を結ぶと閉路はできる
//深さが同じ所は結べない
//深さの差が2以上の奇数のところを選ぶ
int depth[100] = {};
bool seen[100] = {};
void dfs(vector<vector<int>>& g, int nd, int v)
{
    depth[v] = nd;
    seen[v] = true;
    for(auto& nv: g[v])
    {
        if(seen[nv]) continue;
        else
        {
            dfs(g, nd + 1, nv);
        }
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    bool connected[n][n] = {};
    vector<vector<int>> g(n);
    set<pint> ans;
    rep(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
        connected[u][v] = true;
        connected[v][u] = true;
    }
    dfs(g, 0, 0);
    rep(i, n)
    {
        for(int j = i + 1; j < n; j++)
        {
            if((abs(depth[i] - depth[j]) % 2 == 1) & !connected[i][j])
            {
                ans.insert({i, j});
            }
        }
    }
    if(ans.size() % 2 == 1)
    {
        cout << "First" << endl;
        cout << (*(ans.begin())).first + 1 << ' ' << (*(ans.begin())).second + 1 << endl;
        ans.erase(ans.begin());
    }
    else
    {
        cout << "Second" << endl;
    }
    while(true)
    {
        int i, j;
        cin >> i >> j;
        i--;
        j--;
        if(i == -2 && j == -2) break;
        if(ans.find({i, j}) != ans.end())
        {
            ans.erase({i, j});
        }
        else
        {
            break;
        }
        cout << (*(ans.begin())).first + 1 << ' ' << (*(ans.begin())).second + 1 << endl;
        ans.erase(ans.begin());
    }
    return 0;
}