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

ll power(ll a, ll e)
{
    if(e == 0) return 1;
    ll ans = 1;
    rep(i, e)
    {
        ans *= a;
    }
    return ans;
}
int main()
{
    ll n;
    ll a[37] = {};
    a[1] = 9;
    a[2] = 9;
    for(int i = 3; i <= 36; i++)
    {
        a[i] = 10 * a[i - 2];
    }
    a[1]++;
    ll sum[37] = {};
    rep2(i, 36)
    {
        sum[i] = sum[i - 1] + a[i];
    }
    cin >> n;
    ll nc = n;
    ll dig = 0;
    rep2(i, 36)
    {
        if(n <= sum[i])
        {
            dig = i;
            break;    
        }
    }
    ll dicdig = (dig + 1) / 2;
    n -= sum[dig - 1];
    n--;
    string ans = "";
    ll num = n + power(10, (dicdig - 1));
    ans += to_string(num);
    string tmp = ans;
    string t = ans;
    reverse(t.begin(), t.end());
    if(dig % 2 == 1) t = t.substr(1);
    ans += t;
    if(dig == 1)
    {
        ans = to_string(nc - 1);
    }
    cout << ans << endl;
    return 0;
}