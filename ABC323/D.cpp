#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n;
    cin >> n;
    //サイズ10^9が10^9来てもllに収まる
    map<ll,ll> cnt;
    ll ans = 0;
    ll x,y;
    rep(i,n)
    {
        cin >> x >> y;
        cnt[x] = y;
    }
    for(auto& [key,val]: cnt)
    {
        if(cnt[key] >= 2)
        {
            cnt[key*2] += val / 2;
            cnt[key] %= 2; 
        }
        ans += val;
    }
    cout << ans << "\n";
    return 0;
}