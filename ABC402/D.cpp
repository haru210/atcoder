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
    //辺を垂直方向に動かした物が平行->点の1つを+1、1つを-1すれば良い
    //この操作では平均が同じになるので、平均が同じになる点が交わらない?
    //大きい数字側のみでできる辺が困るので、modnする?
    int n, m;
    cin >> n >> m;
    int a[m], b[m];
    map<int, int> absum;
    rep(i, m)
    {
        cin >> a[i] >> b[i];
        int tmp = (a[i] + b[i]) % n;
        absum[tmp]++;
    }
    ll ans = 0;
    int sum = m;
    for(auto& [key, val]: absum)
    {
        sum -= val;
        ans += (ll)sum * (ll)val;
    }
    cout << ans << endl;
    return 0;
}