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
    //0から逆に置きに行くことを考える
    //豆の数は考えず、経路のみ考えれば良い
    int n;
    ll ans = 0;
    cin >> n;
    int a[n + 1];
    vector<vector<int>> g(n); 
    vector<vector<int>> gr(n); 
    a[0] = 0;
    rep2(i, n - 1)
    {
        int c;
        cin >> c;
        rep2(j, c)
        {
            g[i - j].push_back(i);
            gr[i].push_back(i - j);
            if(i + j < n)
            {
                g[i + j].push_back(i);
                gr[i].push_back(i + j);
            }    
        }
    }
    rep2(i, n - 1)
    {
        cin >> a[i];
    }
    queue<int> que;
    vector<int> dist(n, -1);
    dist[0] = 0;
    que.push(0);
    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        for(auto& nv: g[v])
        {
            if(dist[nv] == -1)
            {
                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }
    }
    priority_queue<pint, vector<pint>, less<pint>> gque; 
    rep2(i, n - 1)
    {
        if(a[i] != 0)
        {
            gque.push({dist[i], i});
        }
    }
    while(!gque.empty())
    {
        int v = gque.top().second;
        gque.pop();
        if(a[v] == 0) continue;
        int tmp = inf;
        int tmp_pos = -1;
        bool is_bean = false;
        for(auto& nv: gr[v])
        {
            if(tmp > dist[nv])
            {
                tmp = dist[nv];
                tmp_pos = nv;
                if(a[0] != 0) is_bean = true;
                else is_bean = false;
            }
            else if(tmp == dist[nv])
            {
                if(a[0] != 0)
                {
                    tmp_pos = nv;
                    is_bean = true;
                }
            }
        }
        a[tmp_pos] += a[v];
        a[v] = 0;
        ans++;
        if((!is_bean) && (tmp_pos != 0))
        {
            gque.push({tmp, tmp_pos});
        }
    }
    cout << ans << endl;
    return 0;
}