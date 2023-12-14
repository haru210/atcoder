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
int dy[8] = {1, 1, 1, 0, 0, -1,-1, -1};
int dx[8] = {1, 0, -1, 1, -1, 1, 0, -1};
bool seen[1000][1000] = {};
string s[1000];
int h,w;
void dfs(int vx, int vy)
{
    seen[vy][vx] = true;
    int next_x, next_y;
    rep(i,8)
    {
        next_x = vx + dx[i];
        next_y = vy + dy[i];
        if(next_x < 0 || next_x >= w || next_y < 0 || next_y >= h) continue;
        if(s[next_y][next_x] == '#' && !seen[next_y][next_x]) dfs(next_x, next_y);
    }
}
int main()
{
    int ans = 0;
    cin >> h >> w;
    rep(i,h) cin >> s[i];
    rep(i,h) rep(j,w) if(s[i][j] == '.') seen[i][j] = true;
    rep(i,h)
    {
        rep(j,w)
        {
            if(!seen[i][j] && s[i][j] == '#')
            {
                ans++;
                dfs(j,i);
            }
        }
    }
    cout << ans << endl;
    return 0;
}