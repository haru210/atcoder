#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n1,n2,m;
    int d;
    cin >> n1 >> n2 >> m;
    int a_max = 0,b_max=0;
    vector<vector<int>> g(n1 + n2);
    rep(i,m)
    {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> dist(n1 + n2,-1);
    queue<int> que;
    dist[0] = 0;
    dist[n1 + n2 - 1] = 0;
    que.push(0);
    while(!que.empty())
    {
        int v = que.front();
        que.pop();

        for(int nv: g[v]){
            if(dist[nv] != -1) continue;

            dist[nv] = dist[v] + 1;
            a_max = max(dist[nv],a_max);
            que.push(nv);
        }
    }
    que.push(n1 + n2 - 1);
    while(!que.empty())
    {
        int v = que.front();
        que.pop();

        for(int nv: g[v]){
            if(dist[nv] != -1) continue;

            dist[nv] = dist[v] + 1;
            b_max = max(dist[nv],b_max);
            que.push(nv);
        }
    }
    //for(int v = 0; v < n1 + n2; v++) cout << v + 1 << ':'<< dist[v] << endl;
    d = a_max + b_max;
    d++;
    cout << d << endl;
    return 0;
}