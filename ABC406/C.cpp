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
    int n;
    cin >> n;
    int p[n + 1];
    rep2(i, n) cin >> p[i];
    ll sum_mt[n + 1] = {};
    ll sum_ca[n + 1] = {};
    ll ans = 0;
    //始点を全探索して、二分探索+累積和
    for(int i = 2; i < n; i++)
    {
        sum_mt[i] = sum_mt[i - 1];
        sum_ca[i] = sum_ca[i - 1];
        if(p[i - 1] < p[i] && p[i] > p[i + 1]) sum_mt[i]++;
        if(p[i - 1] > p[i] && p[i] < p[i + 1]) sum_ca[i]++; 
    }
    sum_mt[n] = sum_mt[n - 1];
    sum_ca[n] = sum_ca[n - 1];
    rep2(i, n - 3)
    {
        //caとmtの区間内の数は単調増加
        if(p[i] >= p[i + 1]) continue;
        if(sum_mt[n] - sum_mt[i] == 0 || sum_ca[n] - sum_ca[i] == 0) continue;
        //右端探索
        int ok = i + 1;
        int ng = n + 1;
        while(ng - ok > 1)
        {
            int mid = (ng + ok) / 2;
            if(sum_mt[mid] - sum_mt[i] > 1 || sum_ca[mid] - sum_ca[i] > 1)
            {
                ng = mid;
            }
            else
            {
                ok = mid;
            }
        }
        int right_limit = min(n, ng);
        //左端
        ng = i;
        ok = n;
        while(ok - ng > 1)
        {
            int mid = (ok + ng) / 2;
            if(sum_mt[mid] - sum_mt[i] > 0 && sum_ca[mid] - sum_ca[i] > 0)
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }
        int left_limit = ok + 1;
        ll tmp = right_limit - max(i + 3, left_limit) + 1;
        if(tmp > 0) ans += tmp;
      //  cout << i <<": " << ans << ' '<< left_limit << ' ' << right_limit << endl; 
    }
    cout << ans << endl;
    return 0;
}