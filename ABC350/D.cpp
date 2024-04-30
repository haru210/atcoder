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

bool is_seen[200000] = {};
//各連結成分において全員と友達になれるので、連結成分ごとに人数を数える、引ける数はn人の時(n-1)+(n-2)+...+1なのでn(n-1)/2

void dfs(int v, vector<vector<int>>& g, ll& cnt)
{
    is_seen[v] = true;
    cnt++;
    for(const auto nv: g[v])
    {
        if(is_seen[nv]) continue;
        else
        {
            dfs(nv, g, cnt);
        }
    }
}
int main()
{
    int n,m;
    ll all_line = 0; 
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i,m)
    {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rep(i,n)
    {
        ll cnt;
        if(!is_seen[i])
        {
            cnt = 0;
            dfs(i, g, cnt);
            all_line += (cnt * (cnt - 1)) / 2;
        }
    }
    cout << all_line - m << endl;
    return 0;
}