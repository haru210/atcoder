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
    int h,w;
    cin >> h >> w;
    int x[h][w];
    rep(i,h) rep(j,w) cin >> x[i][j];
    int q;
    cin >> q;
    int a[q],b[q],c[q],d[q];
    rep(i,q)cin >> a[i] >> b[i] >> c[i] >> d[i];
    int sum[h][w] = {0};
    //横方向に累積和をとる
    rep(i,h)
    {
        rep(j,w)
        {
            if(j == 0)sum[i][j] = x[i][j];
            else sum[i][j] = sum[i][j-1] + x[i][j];
        }
    }
    //縦方向に累積和をとる
    rep(j,w)
    {
        rep(i,h)
        {
            if(i == 0) continue;
            sum[i][j] = sum[i-1][j] + sum[i][j];
        }
    }

    /*cout << endl;
    rep(i,h)
    {
        rep(j,w) cout << sum[i][j] << ' ';
        cout << endl;
    }*/

    rep(i,q)
    {
        int ans = 0;
        if(a[i] == 1 && b[i] == 1) ans = sum[c[i]-1][d[i]-1];
        else if(a[i] == 1) ans = sum[c[i]-1][d[i]-1] - sum[c[i]-1][b[i]-2];
        else if(b[i] == 1) ans = sum[c[i]-1][d[i]-1] - sum[a[i]-2][d[i]-1];
        else ans = sum[c[i]-1][d[i]-1] - sum[c[i]-1][b[i]-2] - sum[a[i]-2][d[i]-1] + sum[a[i]-2][b[i]-2];
        cout << ans << endl;
    }
    return 0;
}