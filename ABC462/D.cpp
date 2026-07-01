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

//情報を区間に波及させる+セグ木とかは使えない→imosっぽい
int main()
{
    int n, d;
    cin >> n >> d;
    vector<ll> able_cnt(1000005); //able_cnt[i] := i分に犯行を終えられる人の数
    int last_t = 0;
    ll ans = 0;
    rep(i, n)
    {
        int s, t;
        cin >> s >> t;
        if (t - s >= d)
        {
            able_cnt[s + d]++;
            able_cnt[t + 1]--;
        }
        last_t = max(last_t, t);
    }
    rep2(i, last_t)
    {
        able_cnt[i] = able_cnt[i - 1] + able_cnt[i];
    }
    rep2(i, last_t)
    {
        if (able_cnt[i] >= 2)
        {
            ans += able_cnt[i] * (able_cnt[i] - 1) / 2;
        }
    }
    cout << ans << endl;
    return 0;
}
