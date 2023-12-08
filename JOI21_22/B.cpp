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
pint d[4] = {{1,0}, {-1,0}, {0,1}, {0, -1}};

int main()
{
    int h,w;
    cin >> h >> w;
    string s[h];
    bool color[h][w]; //# := true, . := false
    rep(i,h) cin >> s[i];
    rep(i,h) rep(j,w)
    {
        if(s[i][j] == '#') color[i][j] = true;
        else color[i][j] = false;
    }
    int dist[h][w];
    rep(i,h) rep(j,w) dist[i][j] = -1;
    queue<pint> que;
    dist[0][0] = 0;
    que.push({0,0});
    while(!que.empty())
    {
        pint v = que.front();
        que.pop();
        rep(i,4)
        {
            pint next_v = {v.first + d[i].first, v.second + d[i].second};
            if(next_v.first < 0 || next_v.first >= h || next_v.second < 0 || next_v.second >= w) continue;
            if(dist[next_v.first][next_v.second] != -1) continue;
            if(color[v.first][v.second] == color[next_v.first][next_v.second]) continue;
            dist[next_v.first][next_v.second] = dist[v.first][v.second] + 1;
            que.push(next_v);
        }
    }
    cout << dist[h-1][w-1] << endl;
    return 0;
}