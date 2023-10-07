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
    pint sc[n];
    rep(i,n)
    {
        cin >> sc[i].first >> sc[i].second;
    }
    sort(sc,sc+n);
    rep(i,n)
    {
        cnt[sc[i].first] = sc[i].second;
    }
    ll ans = 0;
    for(auto& [key,val]: cnt)
    {
        if(cnt[key] >= 2)
        {
            cnt[key*2] = cnt[key] / 2;
            ll tmp = cnt[key] %2;
            cnt[key] = tmp; 
        }
        ans += cnt[key];
    }
    cout << ans << "\n";
    return 0;
}