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

pint dif[4] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
int main()
{
    int h, w;
    cin >> h >> w;
    string s[h];
    rep(i, h) cin >> s[i];
    queue<pint> que;
    que.push({0, 0});
    bool seen[h][w] = {};
    int dist[h][w] = {};
    seen[0][0] = true;
    dist[0][0] = 0;
    map<char, vector<pint>> warp;
    set<char> seen_warp;
    rep(i, h)
    {
        rep(j, w)
        {
            warp[s[i][j]].push_back({i, j});
        }
    }
    bool ended = false;
    while(!que.empty())
    {
        pint v = que.front();
        que.pop();
        if(s[v.first][v.second] != '.' && s[v.first][v.second] != '#')
        {
            if(seen_warp.find(s[v.first][v.second]) == seen_warp.end())
            {
                vector<pint>& wnv = warp[s[v.first][v.second]];
                rep(j, wnv.size())
                {
                    if(wnv[j].first == v.first && wnv[j].second == v.second) continue;
                    pint nv = wnv[j];
                    if(seen[nv.first][nv.second]) continue;
                    dist[nv.first][nv.second] = dist[v.first][v.second] + 1;
                    seen[nv.first][nv.second] = true;
                    if(nv.first == h - 1 && nv.second == w - 1)
                    {
                        ended = true;
                        break;
                    }
                    que.push({nv.first, nv.second});
                }
                seen_warp.insert(s[v.first][v.second]);
            }
            
        }
        if(ended) break;
        rep(i, 4)
        {
            pint nv = {v.first + dif[i].first, v.second + dif[i].second};
            if(nv.first == -1 || nv.first == h || nv.second == -1 || nv.second == w) continue;
            if(s[nv.first][nv.second] != '#' && !seen[nv.first][nv.second])
            {
                dist[nv.first][nv.second] = dist[v.first][v.second] + 1;
                seen[nv.first][nv.second] = true;
                if(nv.first == h - 1 && nv.second == w - 1)
                {
                    ended = true;
                    break;
                }
                que.push({nv.first, nv.second});
            }
        }
        if(ended) break;
    }
    if(dist[h - 1][w - 1] == 0) cout << -1 << endl;
    else cout << dist[h - 1][w - 1] << endl;
    return 0;
}