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
//                      5000000000000000000
int main()
{
    ll n,m,k;
    cin >> n >> m >> k;
    //答えで二分探索
    ll ng = 0;
    ll ok = 5000000000000000000;
    ll mid;
    while(ok - ng > 1)
    {
        mid = (ok + ng) / 2;
        ll n_cnt, m_cnt, nm_cnt;
        n_cnt = mid / n;
        m_cnt = mid / m;
        ll nm = lcm(n, m);
        nm_cnt = (mid / nm) * 2;
        ll cnt = (n_cnt + m_cnt) - nm_cnt;
        if(cnt < k) ng = mid;
        else if(cnt >= k) ok = mid;
    }
    cout << ok << endl;
    return 0;
}