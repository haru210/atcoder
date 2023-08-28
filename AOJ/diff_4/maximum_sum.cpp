#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << " No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << " NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n,k;
    cin >> n >> k;
    int a[n];
    int sum[n];
    int ans = -1 * inf;
    rep(i,n)
    {
        cin >> a[i];
    }
    sum[0] = a[0];
    for(int i = 1; i < n; i++)
    {
        sum[i] = sum[i-1] + a[i];
    }
    ans = sum[k-1];
    for(int i = 1; i + k < n;i++)
    {
        ans = max(ans,sum[i+k-1] - sum[i-1]);
    }
    cout << ans << endl;
    return 0;
}