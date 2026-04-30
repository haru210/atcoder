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
    int k, n;
    cin >> n >> k;
    ll a[n];
    rep(i, n) cin >> a[i];
    sort(a, a + n);
    int num = a[0];
    ll cnt = 1;
    vector<ll> tr_cnt;
    rep2(i, n - 1)
    {
        if(a[i] == num)
        {
            cnt++;
        }
        else
        {
            tr_cnt.push_back(cnt * num);            
            num = a[i];   
            cnt = 1;
        }
    }
    tr_cnt.push_back(cnt * num);
    sort(tr_cnt.begin(), tr_cnt.end(), greater<ll>());
    ll ans = 0;
    rep(i, n)
    {
        ans += a[i];
    }
    rep(i, k)
    {
        if(i >= tr_cnt.size()) break;
        ans -= tr_cnt[i];
    }
    cout << ans << endl;
    return 0;
}