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
    int n,q;
    cin >> n >> q;
    int r[n];
    ll query[q];
    rep(i,n) cin >> r[i];
    rep(i,q) cin >> query[i];
    sort(r,r+n);
    ll sum[n];
    sum[0] = r[0];
    rep2(i,n-1)
    {
        sum[i] = sum[i-1] + r[i];
    }
    rep(i,q)
    {
        int ans = lower_bound(sum,sum+n, query[i]) - sum;
        if(ans == n) cout << n << endl;
        else
        {
            if(sum[ans] != query[i]) ans--;
            ans++;
            cout << ans << endl; 
        }
    }
    return 0;
}