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

bool seen[1000000 + 1] = {};
int ans = 0;
map<int, int> cnt;

void dfs(vector<vector<int>>& g, int v, int bud, int bde)
{
    seen[v] = true;
    int ud = bde;
    int de = min(bud, bde) + cnt[v];
    if(g[v].size() == 0)
    {
        ans += min(ud, de);
    }
    else
    {
        dfs(g, g[v][0], ud, de);
    }
}

int main()
{
    //3つつながってる時に真ん中を消すか両端を消すか
    int n, d;
    cin >> n >> d;
    int a[n];
    rep(i, n) cin >> a[i];
    sort(a, a + n);
    int leng = 1;
    int num = a[0];
    rep(i, n)
    {
        cnt[a[i]]++;
    }
    if(d == 0)
    {
        for(auto& [key, val] : cnt)
        {
            ans += (val - 1);
        }
    }
    else
    {
        vector<vector<int>> g(1000000);
        for(auto& [key, val] : cnt)
        {
            if(cnt.find(key + d) != cnt.end())
            {
                g[key].push_back(key + d);
            }
        }
        for(auto& [key, val] : cnt)
        {
            if(!seen[key] && g[key].size() != 0)
            {
                
                dfs(g, key, 0, 0);
            } 
        }
    }
    cout << ans << endl;
    return 0;
}