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
    ll n, m;
    cin >> n >> m;
    ll ans = 1;
    ll e = 1;
    bool overflow = false;
    rep(i, m)
    {
        e *= n;
        if(e > (ll)1000000000)
        {  
            overflow = true;
            break;
        } 
        ans += e;
        if(ans > (ll)1000000000)
        {
            overflow = true;
            break;
        }
    }
    if(overflow) cout << "inf\n";
    else cout << ans << endl;
    return 0;
}