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

//移動できるマスを自由マスとする
//各連結成分が多い自由マス+そこから移動できるマス

bool is_seen[1000][1000] = {};
bool unfree[1000][1000] = {};
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int h, w;
string s[1000];
void dfs(int y, int x, set<pint>& went)
{
    went.insert({y, x});
    is_seen[y][x] = true;
    rep(i, 4)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
        if(is_seen[ny][nx]) continue;
        bool free = true;
        if(ny - 1 >= 0) if(s[ny - 1][nx] == '#') free = false;
        if(ny + 1 < h) if(s[ny + 1][nx] == '#') free = false;
        if(nx - 1 >= 0) if(s[ny][nx - 1] == '#') free = false;
        if(nx + 1 < w) if(s[ny][nx + 1] == '#') free = false;
        if(free)
        {
            dfs(ny, nx, went);
        }
        else
        {
            went.insert({ny, nx});
            is_seen[y][x] = true;
        }
    }
}

int main()
{
    int ans = 1;
    cin >> h >> w;
    rep(i,h) cin >> s[i];
    rep(i,h)
    {
        rep(j,w)
        {
            if(s[i][j] == '#') continue;
            if(i - 1 >= 0) if(s[i-1][j] == '#') continue;
            if(j - 1 >= 0) if(s[i][j-1] == '#') continue;
            if(j + 1 < w) if(s[i][j+1] == '#') continue;
            if(i + 1 < h) if(s[i+1][j] == '#') continue;
            set<pint> went;
            dfs(i, j, went);
            ans = max(ans, (int)went.size());
        }
    }
    cout << ans << endl;
    return 0;
}