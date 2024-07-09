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

#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

// .の位置を遷移に持たせる?
int main()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    s += "..";
    t += "..";
    queue<pair<string, int>> que;
    map<string, int> dis;
    dis[s] = 0;
    que.push({s, n});
    int cnt = 0;
    bool end = false;
    while(!que.empty())
    {
        string v = que.front().first;
        int dot = que.front().second;
        que.pop();
        int vd = dis[v];
        rep(i, v.size() - 1) //移動するマスの場所を探索
        {
            if(i - 1 == dot || i == dot || i + 1 == dot) continue;
            cnt++;
            string nv = v;
            nv[dot] = nv[i];
            nv[dot + 1] = nv[i + 1];
            nv[i] = '.';
            nv[i + 1] = '.';
            int ndot = i;
            if(dis[nv] == 0)
            {
                dis[nv] = vd + 1;
                if(nv == t) end = true;
                que.push({nv, ndot});
            }
            if(end) break;
        }
    }
    if(s == t) cout << 0 << endl;
    else
    {
        if(dis[t] == 0) cout << -1 << endl;
        else cout << dis[t] << endl;
    }
    return 0;
}