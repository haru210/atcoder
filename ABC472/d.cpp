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
    int h, w, k;
    cin >> h >> w >> k;
    string s[h];
    rep(i, h) cin >> s[i];
    bool row[h] = {}; //その行に爆弾があるかどうか
    bool column[w] = {}; //その列に爆弾があるかどうか
    queue<pint> que;
    vector<vector<int>> dist(h, vector<int>(w, -1));
    int ans = 0;
    rep(i, h)
    {
        rep(j, w)
        {
            if (s[i][j] == '#')
            {
                row[i] = true;
                column[j] = true;
            }
        }
    }
    rep(i, h)
    {
        rep(j, w)
        {
            if (!row[i] && !column[j])
            {
                que.push({i, j});

                dist[i][j] = 0;
            }
        }
    }
    while (!que.empty())
    {
        pint v = que.front();
        que.pop();
        int i = v.first;
        int j = v.second;
        if (i != 0 && s[i - 1][j] == '.' && dist[i - 1][j] == -1)
        {
            dist[i - 1][j] = dist[i][j] + 1;
            que.push({i - 1, j});
        }
        if (i != h - 1 && s[i + 1][j] == '.' && dist[i + 1][j] == -1)
        {
            dist[i + 1][j] = dist[i][j] + 1;
            que.push({i + 1, j});
        }
        if (j != 0 && s[i][j - 1] == '.' && dist[i][j - 1] == -1)
        {
            dist[i][j - 1] = dist[i][j] + 1;
            que.push({i, j - 1});
        }
        if (j != w - 1 && s[i][j + 1] == '.' && dist[i][j + 1] == -1)
        {
            dist[i][j + 1] = dist[i][j] + 1;
            que.push({i, j + 1});
        }
    }
    rep(i, h)
    {
        rep(j, w)
        {
            if (dist[i][j] != -1 && dist[i][j] <= k) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
