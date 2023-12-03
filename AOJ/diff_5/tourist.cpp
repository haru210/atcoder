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
    int n,m;
    int ans = 0;
    cin >> n >> m;
    int a[m];
    int s[n-1]; //i個目からi+1個目の距離
    int sum[n] = {0}; //0～i番目の距離
    rep(i,n - 1) cin >> s[i];
    rep(i,m) cin >> a[i];
    sum[0] = 0;
    for(int i = 1; i < n; i++)
    {
        sum[i] = sum[i-1] + s[i-1];
    }
    int now = 0;
    int next = 0;
    rep(i,m)
    {
        next = now + a[i];
        if(now - 1 < 0) ans += sum[next];
        else if(a[i] > 0)
        ans += sum[next] - sum[now];
        else if(a[i] < 0)
        ans += sum[now] - sum[next];
        ans %= 100000;
        now = next;
    }
    cout << ans << endl;
    return 0;
}