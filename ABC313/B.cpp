#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << " No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << " NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
//弱いほうから強いほうへの有向グラフを考える。
//すべての点にたどり着ける＝さいつよ
int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    bool found = false;
    rep(i,m)
    {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
    }
    rep(i,n){
        vector<int> dist(n,-1);
        queue<int> que;
        dist[i] = 0;
        que.push(i);

        while(!que.empty())
        {
            int v = que.front();
            que.pop();

            for(int nv: g[v])
            {
                if(dist[nv] != -1) continue;

                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }
        bool ok = true;
        rep(j,n)
        {
            if(dist[j] == -1) ok = false;
        }
        if(ok)
        {
            cout << i + 1 << endl;
            found = true;
            break;
        }
    }
    if(!found) cout << -1 << endl;
    return 0;
}