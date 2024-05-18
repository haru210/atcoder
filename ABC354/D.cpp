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
//各マス黒、白、半分になってる
//2x4長方形ごとに周期的
int parts[2][4] = {{2, 3, 3, 4}, {3, 6, 7, 8}};
ll calc_sum(ll i, ll j)
{
    ll ans  = 0;
    ll a, b, c, d;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    a = (i / 2) *  (j  / 4);
    a *= 8;
    ans += a;
    if(j % 4 != 0) b = parts[1][(j % 4) - 1] * (i / 2);
    if(i % 2 != 0) c = parts[0][3] * (j / 4);
    if(j % 4 != 0 && i % 2 != 0)
    {
        d = parts[0][(j % 4) - 1];
    }
    return a + b + c + d;
}   
int main()
{
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    a += 1000000000;
    b += 1000000000;
    c += 1000000000;
    d += 1000000000;
    cout << calc_sum(d, c) - calc_sum(b, c) - calc_sum(d, a) + calc_sum(b, a) << endl;
    return 0;
}