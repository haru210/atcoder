#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 1e9;
const long long l_inf = 9223372036854775807;
pint d[4] = {{1,0}, {-1,0}, {0,1}, {0, -1}};
int main()
{
    int h,w,n;
    cin >> h >> w >> n;
    string s[h];
    pint fac_pos[11]; //1-indexed
    rep(i,h)
    {
        cin >> s[i];
        rep(j,w)
        {
            if(isdigit(s[i][j]))
            {
                int tmp = s[i][j] - '0';
                fac_pos[tmp] = {i,j};
            }
            if(s[i][j] == 'S')
            {
                fac_pos[0] = {i,j};
            }
        }
    }
    ll ans = 0;
    rep(i,n)
    {
        int dist[h][w];
        rep(j,h) rep(k,w) dist[j][k] = -1;
        queue<pint> que;
        dist[fac_pos[i].first][fac_pos[i].second] = 0;
        que.push(fac_pos[i]);
        while(!que.empty())
        {
            pint v = que.front();
            que.pop();
            rep(j,4)
            {
                pint next_v = {v.first + d[j].first, v.second + d[j].second};
                if(next_v.first < 0 || next_v.first >= h || next_v.second < 0 || next_v.second >= w) continue;
                if(s[next_v.first][next_v.second] == 'X' || dist[next_v.first][next_v.second] != -1) continue;
                dist[next_v.first][next_v.second] = dist[v.first][v.second] + 1;
                que.push(next_v);
            }
        }
        ans += dist[fac_pos[i+1].first][fac_pos[i+1].second];
    }
    cout << ans << endl;
    return 0;
}