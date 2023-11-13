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
const long long l_inf = 10000000000;
//コストの最小化は累積和を用いると可能
//建築できないところを選ばないように、建築できないところを大きな値にする
ll sum[1005][1005];
ll cost[1005][1005];
int main()
{
    int h,w,a,b; //縦、横、縦、横
    cin >> w >> h >> b >> a;
    rep2(i,h) rep2(j,w)
    {
        cin >> cost[i][j];
        if(cost[i][j] == -1) cost[i][j] = l_inf;
    }
    //累積和の準備
    sum[0][0] = 0;
    rep2(i,w) sum[0][i] = 0;
    rep2(i,h) sum[i][0] = 0;
    //累積和の計算
    rep2(i,h)
    {
        rep2(j,w)
        {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + cost[i][j];
        }
    }
    ll ans = l_inf;
    //建設位置を全探索
    for(int i = a; i <= h; i++)
    {
        for(int j = b; j <= w; j++)
        {
            ll tmp = sum[i][j] - sum[i-a][j] - sum[i][j-b] + sum[i-a][j-b];
            ans = min(ans, tmp);
        }
    }
    cout << ans << endl;
    return 0;
}