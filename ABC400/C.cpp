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
    //Nまでの数の中で2^Nの個数の方が少ない　ため2^Nに対して全探索する
    //各2^Nに対してj^2がN/(2^i)を越えないjを求める
    //bが2の因数を偶数個持っている場合それをa側に渡すと同じ数ができる
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i = 2; i <= n; i *= 2)
    {
        ll tmpn = n / i;
        ll ng = tmpn + 1;
        ll ok = -1;
        while(ng - ok > 1)
        {
            ll mid = (ng + ok) / 2;
            bool overn = false;
            if(mid > 1000000000)
            {
                overn = true;
            }
            else if(mid * mid > tmpn)
            {
                overn = true;
            }
            if(overn)
            {
                ng = mid;
            }
            else
            {
                ok = mid;
            }
        }
        ok = (ok + 1) / 2;
        ans += ok;
    }
    cout << ans << endl;
    return 0;
}