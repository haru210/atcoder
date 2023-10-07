#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    int a[n];
    int b[m];
    int ans[m] = {0};
    rep(i,n) cin >> a[i];
    rep(i,m)
    {
        cin >> b[i];
    }
    rep(i,m)
    {
        int tmp = lower_bound(a,a+n,b[i]) - a;
        if(tmp - 1 >= 0) ans[i] = max(ans[i], k - abs(b[i] - a[tmp-1]));
        if(tmp < n)ans[i] = max(ans[i],k - abs(b[i] - a[tmp]));
    }
    rep(i,m) cout << ans[i] << endl;
    return 0;
}