#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
//1->3->2->4みたいなルートがあるので、単純なDPだとはじかれそう
//グラフにしてダイクストラ
bool con[200010] = {};
ll cur[200010] = {};
int main()
{
    int n;
    cin >> n;
    vector<vector<pll>> g(n);
    rep(i, n-1)
    {
        int a,b,x;
        cin >> a >> b >> x;
        x--;
        g[i].push_back({i+1, a});
        g[i].push_back({x, b});
    }
    rep(i, n) cur[i] = l_inf;
    cur[0] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({cur[0], 0});

    while(!q.empty())
    {
        int np = q.top().second; q.pop();
        if(con[np]) continue;
        con[np] = true;
        rep(i, g[np].size())
        {
            int nv = g[np][i].first;
            int cost = g[np][i].second;
            if(cur[nv] > cur[np] + cost)
            {
                cur[nv] = cur[np] + cost;
                q.push({cur[nv], nv});
            }
        }
    }
    cout << cur[n-1] << endl;
    return 0;
}