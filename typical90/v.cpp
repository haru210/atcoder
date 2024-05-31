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
    ll a, b, c;
    cin >> a >> b >> c;
    ll sz = __gcd(__gcd(a, b), c);
    ll ans = a / sz - 1;
    ans += b / sz - 1;
    ans += c / sz - 1;
    cout << ans << endl;
    return 0;
}