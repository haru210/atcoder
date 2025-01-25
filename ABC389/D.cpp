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

// 1/4計算すれば良い
// 左に行って一個下がるかどうか計算してみる
int main()
{
    ll r;
    cin >> r;
    ll ans = (r - 1) * 4 + 1; // 1/4に分けた時重複する部分
    ll max_y = r - 1;
    rep2(i, r - 1)
    {
        while(true)
        {
            ll tmp_x = i * 10 + 5;
            ll tmp_y = max_y * 10 + 5;
            if(tmp_x * tmp_x + tmp_y * tmp_y <= 100 * r * r)
            {
                break;
            }
            else
            {
                max_y--;
            }
        }
        ans += max_y * 4;
    }
    cout << ans << endl;
    return 0;
}
