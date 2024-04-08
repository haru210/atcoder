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
    ll n;
    cin >> n;
    ll x[n+1], y[n+1];
    rep2(i,n) cin >> x[i] >> y[i];
    rep2(i,n)
    {
        ll max_dis = 0;
        ll max_num = -1;
        rep2(j,n)
        {
            if(i == j) continue;
            ll dis = ((x[i] - x[j]) * (x[i] - x[j])) + ((y[i] - y[j]) * (y[i] - y[j]));
            if(max_dis < dis)
            {
                max_dis = dis;
                max_num = j;
            }
        }
        cout << max_num << endl;
    }
    return 0;
}