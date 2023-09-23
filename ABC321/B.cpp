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
    int n,x;
    cin >> n >> x;
    int a[n];
    rep(i,n-1) cin >> a[i];
    sort(a,a+(n-1));
    int sum = 0;
    int sum_0 = a[0]; //0をとることで、最少スコアを0にする時のスコア
    rep2(i, n-3)
    {
        sum += a[i];
        sum_0 += a[i];
    }
    int ans = x - sum;
    //x - sumがa[n-2]以下なら可能
    if(ans > a[n-2]) cout << -1;
    else
    {
        if(sum_0 >= x) cout << 0 << endl;
        else
        {
            cout << ans << endl;
        }
    }
    return 0;
}