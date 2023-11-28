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

bool ice[92][92] = {};  
bool seen[92][92] = {false};
ll ans = 0;

void dfs(pint v, ll chain)
{
    seen[v.first][v.second] = true;
    vector<pint> next_v;
    if(ice[v.first + 1][v.second] && !seen[v.first+1][v.second])
    {
        next_v.push_back({v.first+1,v.second});
    }
    if(ice[v.first - 1][v.second] && !seen[v.first-1][v.second])
    {
        next_v.push_back({v.first-1,v.second});
    }
    if(ice[v.first][v.second+1] && !seen[v.first][v.second+1])
    {
        next_v.push_back({v.first,v.second+1});
    }
    if(ice[v.first][v.second-1] && !seen[v.first][v.second-1])
    {
        next_v.push_back({v.first,v.second-1});
    }
    rep(i,next_v.size())
    {
        dfs(next_v[i], chain + 1);
    }
    seen[v.first][v.second] = false;
    ans = max(chain, ans);
}
int main()
{
    int n,m;
    cin >> m >> n;
    rep2(i,n) rep2(j,m) cin >> ice[i][j];
    rep2(i,n)
    {
        rep2(j,m)
        {
            rep2(k,n) rep2(l,m)
            {
                seen[k][l] = false;
            }
            if(ice[i][j])
            {
                dfs({i,j}, 1);
            }
      }
    }
    cout << ans << endl;
    return 0;
}