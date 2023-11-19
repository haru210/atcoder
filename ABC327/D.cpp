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
    cin >> n >> m;
    int a[m],b[m];
    rep(i,m)
    {
        cin >> a[i];
        a[i]--;
    }
    rep(i,m) 
    {
        cin >> b[i];
        b[i]--;
    }
    vector<vector<int>> g(n);
    rep(i,m)
    {
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    bool ok = true;
    vector<int> dist(n, -1);
    queue<int> que;
    rep(i,n)
    {
        if(dist[i] != -1) continue;
        dist[i] = 0;
        que.push(i);
        while(!que.empty())
        {
            int v = que.front();
            que.pop();
            for (auto nv : g[v]) 
            {           
                if(dist[nv] == -1)
                {
                    
                    dist[nv] = dist[v] + 1;
                    que.push(nv);
                }
                else 
                {
                    if(dist[v] == dist[nv]) ok = false;
                }
            }
        }
    }
    YesNo(ok);
    return 0;
}