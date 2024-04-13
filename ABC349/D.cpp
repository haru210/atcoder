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

int main()
{
    ll exp_2[61] = {0};
    exp_2[0] = 1;
    ll ans = 0;
    vector<pll> ans_list;
    rep2(i,60)
    {
        exp_2[i] = exp_2[i-1] * 2;
    }
    ll l,r;
    cin >> l >> r;
    ll p = r;
    while(p > l)
    {
        ll cnt = 0;
        ll tmp = p;
        while(tmp %2 == 0)
        {
            tmp /= 2;
            cnt++;
        }
        while(p - exp_2[cnt] < l)
        {
            cnt--;
        }
        ans++;
        ans_list.push_back({p - exp_2[cnt], p});
        p -= exp_2[cnt];
    }
    
    reverse(ans_list.begin(), ans_list.end());
    cout << ans << endl;
    rep(i,ans_list.size())
    {
        cout << ans_list[i].first << ' ' << ans_list[i].second << endl;
    }
    return 0;
}