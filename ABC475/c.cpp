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
    ll n, s, l;
    cin >> n >> s >> l;
    s--;
    ll a[n - 1];
    rep(i, n - 1) cin >> a[i];
    ll ans = 0;
    //左に行けるだけ行く→減らしつつ右に行く距離を増やしていく
    //逆もあるね
    //一番多いところ
    ll distance[n]= {};
    for (int p = s; p >= 1; p--)
    {
        distance[p - 1] = distance[p] + a[p - 1];
    }
    for (int p = s; p < n - 1; p++)
    {
        distance[p + 1] = distance[p] + a[p];
    }
    for (int i = 0; i <= s; i++)
    {
        for (int j = s; j < n; j++)
        {
            ll leftwalk = distance[i] * 2 + distance[j];
            ll rightwalk = distance[i] + distance[j] * 2;
            ll walk = min(leftwalk, rightwalk);
            if (walk <= l)
            {
                ans = max(ans, (s - i) + (j - s) + 1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
