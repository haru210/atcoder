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
//int同士の掛け算をllに代入、は代入されるときにしかキャストが起こらない！
int main()
{
    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];
    vector<ll> before(200010, -1);
    ll ans = 0;
    rep(i, n)
    {
        if(before[a[i]] == -1)
        {
            ans += (ll)(i + 1) * (ll)(n - i);
            before[a[i]] = i;
        }
        else
        {
            ans += (ll)(i - before[a[i]]) * (ll)(n - i);
            before[a[i]] = i;
        }
    }
    cout << ans << endl;
    return 0;
}