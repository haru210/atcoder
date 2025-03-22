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
//シンプルな二次元dpは即死する

int main()
{
    ll n, m;
    cin >> n >> m;
    priority_queue<pll, vector<pll>, greater<pll>> que;
    ll p[n];
    ll b[n]= {};
    ll mon = 0;
    ll ans = -1;
    rep(i, n) cin >> p[i];
    rep(i, n)
    {
        que.push(make_pair(p[i], i));
    }
    do
    {
        ans++;
        pll tmp = que.top();
        que.pop();
        mon += tmp.first;
        b[tmp.second]++;
        ll next_price = p[tmp.second] * ((b[tmp.second] + 1) * 2 - 1);
        que.push(make_pair(next_price, tmp.second));
    }while(mon <= m);
    cout << ans << endl;
    return 0;
}