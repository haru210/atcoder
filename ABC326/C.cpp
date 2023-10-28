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
    //M個分の数字を区間に入れられる
    //したがって各数字からM個先までにいくつ数字があるか探索すればよい
    //全探索だとTLEする
    //ソートして二分探索
    //leftをその数字にできるのである程度高速化もできてる
    int n,m;
    cin >> n >> m;
    int a[n];
    int ans = 0;
    rep(i,n) cin >> a[i];
    sort(a,a+n);
    rep(i,n)
    {
        int num_index = lower_bound(a+i, a+n, a[i]+m) - a;
        int cnt = num_index - i;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}