#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n,m;
    int ans = 0;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i,m)
    {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> dist(n,-1);
    queue<int> que;
    dist[0] = 0;
    que.push(0);

    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        for(const auto& next_v: g[v])
        {
            if(dist[next_v] != -1) continue;

            dist[next_v] = dist[v] + 1;
            que.push(next_v);
        }
    }
    rep(i,n)
    {
        if(dist[i] > 0 && dist[i] <= 2) ans++;
    }
    cout << ans << endl;
    return 0;
}