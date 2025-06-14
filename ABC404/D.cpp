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

int n, m;
int c[10];
ll ans = l_inf;

void dfs(vector<vector<int>>& zoo, ll mon, int znum, vector<int>& cnt)
{
    rep(i, 3) //行く回数
    {
        ll mon_tmp = mon;
        mon_tmp += (ll)c[znum] * i; 
        rep(j, zoo[znum].size())
        {
            cnt[zoo[znum][j]] += i;
        }
        if(znum == n - 1)
        {
            bool ok = true;
            rep(j, m)
            {
                if(cnt[j] < 2) ok = false;
            }
            if(ok) 
            {
                ans = min(mon_tmp, ans);
            }
            rep(j, zoo[znum].size())
            {
                cnt[zoo[znum][j]] -= i;
            }
        }    
        else
        {
            dfs(zoo, mon_tmp, znum + 1, cnt);
            rep(j, zoo[znum].size())
            {
                cnt[zoo[znum][j]] -= i;
            }
        }
    }
}

int main()
{
    //各動物園に行く回数は2回までなので、全探索する
    //3進数bit全探索は面倒なのでdfsする
    cin >> n >> m;
    rep(i, n) cin >> c[i];
    vector<vector<int>> zoo(n);
    rep(i, m)
    {
        int k;
        cin >> k;
        rep(j, k)
        {
            int a;
            cin >> a;
            a--;
            zoo[a].push_back(i);
        }
    }
    vector<int> cnt(m);
    rep(i, m) cnt[i] = 0;
    dfs(zoo, 0, 0, cnt);
    cout << ans << endl;
    return 0;
}