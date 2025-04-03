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
    //BFSで移動する順番は最短経路順なので、行き方を足していく
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<int> que;
    bool seen[n] = {};
    ll ans[n] = {};
    ll dist[n] = {};
    ans[0] = 1;
    que.push(0);
    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        for(const auto& nv: g[v])
        {
            if(!seen[nv])
            {
                seen[nv] = true;
                que.push(nv);
                dist[nv] = dist[v] + 1;
            }
            if(dist[nv] > dist[v])
            {
                ans[nv] += ans[v];
                ans[nv] %= 1000000007;
            }

        }
    }
    cout << ans[n - 1] << endl;
    return 0;
}