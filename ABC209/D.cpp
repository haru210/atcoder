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

//道路がn-1本なので絶対に木になるはず(辺ごとに新しい街をつなぐ必要があるので、閉路を作る辺を出せない)
//根からの深さの差が奇数なら道で、偶数なら街？
int main()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> dist(n, -1);
    queue<int> que;
    dist[0] = 0;
    que.push(0);
    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        for(int& nv : g[v])
        {
            if(dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }
    rep(i, q)
    {
        int c, d;
        cin >> c >> d;
        c--;
        d--;
        int di = abs(dist[c] - dist[d]);
        if(di % 2 == 0) cout << "Town\n";
        else cout << "Road\n";
    }
    return 0;
}