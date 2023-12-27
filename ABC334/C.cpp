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
    int n,k;
    cin >> n >> k;
    int a[k];
    ll ans = 0;
    rep(i,k) cin >> a[i];
    if(k % 2 == 0)
    {
        for(int i = 0; i < k - 1; i += 2)
        {
            ans += a[i+1] - a[i];
        }
    }
    else if(k != 1)
    {
        ans = l_inf;
        //使わない靴下を全探索
        //前からと後ろからの累積和を計算して、使わない靴下の左側と右側に分けて計算する
        //余りが出る場合使わない靴下の両端をペアにする
        ll sum_f[k] = {};
        ll sum_b[k] = {};
        sum_f[1] = a[1] - a[0];
        sum_b[k - 2] = a[k-1] - a[k-2];
        for(int i = 3; i < k - 1; i+= 2)
        {
            sum_f[i] = sum_f[i - 2] + (a[i] - a[i-1]);
        }
        for(int i = k - 4; i > 0; i -= 2)
        {
            sum_b[i] = sum_b[i + 2] + (a[i+1] - a[i]);
        }
        rep(i,k)
        {
            ll tmp = 0;
            //両端を結ぶべきかどうか
            //iが偶数なら結ばなくて良い(0-indexedより)
            //奇数なら端ではないので配列外参照しない
            if(i % 2 == 1)
            {
                tmp += a[i+1] - a[i];
                if(i - 2 > 0) tmp += sum_f[i-2];
                if(i + 2 < k) tmp += sum_b[i+2];
            }
            else
            {
                if(i - 1 > 0) tmp += sum_f[i-1];
                if(i + 1 < k) tmp += sum_b[i+1];
            }
            ans = min(ans, tmp);
        }
    }
    cout << ans << endl;
    return 0;
}