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

int main()
{
    int n;
    cin >> n;
    ll a[n];
    rep(i, n) cin >> a[i];
    vector<ll> sb;
    vector<pll> lan;
    if(n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    rep(i, n - 1)
    {
        sb.push_back(a[i+1] - a[i]);
    }
    int before = sb[0];
    int ln = 1;
    rep2(i, sb.size() - 1)
    {
        if(sb[i] != before)
        {
            lan.push_back({before, ln});
            ln = 1;
            before = sb[i];
        }
        else
        {
            ln++;
        }
    }
    lan.push_back({before, ln});
    ll ans = 0;
    rep(i, lan.size())
    {
        ans += (lan[i].second + 1) * lan[i].second / 2;
    }
    ans += n;
    cout << ans << endl;
    return 0;
}