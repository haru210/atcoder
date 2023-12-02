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
ll square[2000000] = {0};
int main()
{
    ll d;
    ll ans = l_inf;
    cin >> d;
    for(ll i = 1; i *i<= 2000000000000; i++)
    {
        square[i] = i * i;
    }
    for(ll i = 1;; i++)
    {
        ll y = lower_bound(square, square+2000000, abs(i * i - d)) - square;
        ll tmp;
        if(y != 0)tmp = min(abs(i * i + square[y] - d), abs(i * i + square[y-1] - d));
        else tmp = abs(i * i - d);
        ans = min(tmp, ans);
        if(i * i >= d) break;
    }
    cout << ans << endl;
    return 0;
}