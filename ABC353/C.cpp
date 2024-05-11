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

//2*10^8になることはないので、越えたら10^8を引く、と考えてもよい
int main()
{
    ll n;
    cin >> n;
    ll a[n];
    rep(i, n) cin >> a[i];
    sort(a, a + n);
    ll sum = 0;
    rep(i, n)
    {
        sum += a[i] * (n-1);
        ll tar = 100000000 - a[i];
        int ind = lower_bound(a + i + 1, a + n, tar) - a;
        if(ind == n) continue;
        else sum -=  (n - (ll)ind) * 100000000;
        
    }
    cout << sum << endl;
    return 0;
}