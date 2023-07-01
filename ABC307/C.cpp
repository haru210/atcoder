#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
//制約が小さい→全探索で解ける？

int main()
{
    int h_a,w_a,h_b,w_b,h_x,w_x;
    int l_a = inf,r_a = 0,u_a = inf,d_a = 0;
    int l_b = inf,r_b = 0,u_b = inf,d_b = 0;
    string a[10],b[10],x[10];
    cin >> h_a >> w_a;
    rep(i, h_a) cin >> a[i];
    cin >> h_b >> w_b;
    rep(i, h_b) cin >> b[i];
    cin >> h_x >> w_x;
    rep(i, h_x) cin >> x[i];
    bool flag = false;
    bool YNflag = false;
    //シャープ部分を抽出（周囲の.を切り取るイメージ）
    rep(i, h_a)
    {
        rep(j,w_a)
        {
            if(a[i][j] == '#')
            {
                l_a = min(l_a,j);
                r_a = max(r_a,j);
                u_a = min(u_a,i);
                d_a = max(d_a,i); 
            }
        }
    }
    if(l_a == inf) l_a = 0;
    if(u_a == inf) u_a = 0;
    //cout << l_a << r_a << u_a << d_a << endl;
    rep(i, h_b)
    {
        rep(j,w_b)
        {
            if(b[i][j] == '#')
            {
                l_b = min(l_b,j);
                r_b = max(r_b,j);
                u_b = min(u_b,i);
                d_b = max(d_b,i); 
            }
        }
    }
    if(l_b == inf) l_b = 0;
    if(u_b == inf) u_b = 0;
    if((h_x > d_a - u_a) || (h_x > d_b - u_b) ||(w_x > r_a - l_a) || (w_x > r_b - l_b)){
        rep(i_a,h_x - (d_a - u_a))rep(j_a,w_x - (r_a - l_a)) rep(i_b, h_x- (d_b - u_b)) rep(j_b,w_x - (r_b - l_b))
        {
            char c[h_x][w_x];
            rep(i,h_x) rep(j,w_x) c[i][j] = '.';
            //cを描画
            for(int i = u_a; i <= d_a;i++)
            {
                for(int j = l_a; j <= r_a;j++)
                {
                    
                    if(a[i][j] == '#') c[i_a + i][j_a + j] = '#';
                }
            }
            for(int i = u_b; i <= d_b;i++)
            {
                for(int j = l_b; j <= r_b;j++)
                {
                    if(b[i][j] == '#') c[i_b + i][j_b + j] = '#';
                }
            }
            //チェック
            flag = true;
            for(int i = 0; i < h_x;i++)
            {
                for(int j = 0; j < w_x;j++)
                {
                    if(c[i][j] != x[i][j]) flag = false;
                }
            }
            if(flag) {
                YNflag = true;
            }
        }
    }
    if(YNflag) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}