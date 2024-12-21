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
    //開始位置は1~nなので、全探索できそう
    ll n, s;
    bool ans = false;
    cin >> n >> s;
    ll a[n];
    rep(i, n) cin >> a[i];
    ll sum[n] = {};
    sum[0] = a[0];
    rep2(i, n - 1) sum[i] = sum[i - 1] + a[i];
    rep(i, n)
    {
        ll target = s;
        if(target == 0)
        {
            ans = true;
            break;
        }
        //必要な分周回する
        ll fl;
        if(i == 0) fl = 0;
        else fl = sum[n - 1] - sum[i - 1];
        if(target < fl) continue;
        target -= fl;
        ll loop = target / sum[n - 1];
        target -= (loop * sum[n - 1]);
        if(target == 0)
        {
            ans = true;
            break;
        }
        bool ok = binary_search(sum, sum + n, target);
        if(ok)
        {
            ans = true;
            break;
        }
    }
    YesNo(ans);
    return 0;
}