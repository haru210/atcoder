#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#pragma GCC target("avx")
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
vector<vector<int>> g(300000);
int main()
{
    int n;
    cin >> n;
    ll rem_cost[n] = {};
    ll root_sum = 0;
    ll root_max = 0;
    rep(i,n-1)
    {
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dist(n, -1);
    queue<int> que;
    dist[0] = 0;
    que.push(0);
    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        for(auto&  next_v: g[v])
        {
            if(dist[next_v] != -1) continue;
            dist[next_v] = dist[v] + 1;
            que.push(next_v);
        }
    }
    priority_queue<pint, vector<pint>, less<pint>> q;
    rep(i,n)
    {
        q.push(make_pair(dist[i], i));
    }
    int max_dist = q.top().first;
    while(!q.empty())
    {
        pint tmp = q.top();
        ll cos_tmp = inf;
        q.pop();
        rem_cost[tmp.second]++;
        rep(i,g[tmp.second].size())
        {
            if(g[tmp.second][i] != 0)
            {
                rem_cost[g[tmp.second][i]] += rem_cost[tmp.second];
            }
            else
            {
                root_sum += rem_cost[tmp.second];
                root_max = max(root_max, rem_cost[tmp.second]);
            }
        }
    }
    cout << (root_sum - root_max) + 1 << endl;
    return 0;
}