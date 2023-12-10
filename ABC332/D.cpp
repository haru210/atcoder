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

int h,w;

void swap_s(int a1[5][5], int s_line)
{
    int tmp[5][5] = {};
    rep(i,h)
    {
        rep(j,w)
        {
            if(j == s_line)
            {
                tmp[i][j] = a1[i][j+1];
            }
            else if(j == s_line + 1)
            {
                tmp[i][j] = a1[i][j-1];
            }
            else
            {
                tmp[i][j] = a1[i][j];
            }
        }
    }
    rep(i,h) rep(j,w) a1[i][j] = tmp[i][j];
}
int main()
{
    //同じ操作をすると順番にかかわらずもとに戻るので、
    //bit全探索で全操作する
    int ans = inf;
    cin >> h >> w;
    int a[5][5];
    int b[5][5];
    int copy[5][5];
    rep(i,h) rep(j,w) cin >> a[i][j];
    rep(i,h) rep(j,w) cin >> b[i][j];
    //下w-1ビット列スワップ 上h-1ビット行スワップ
    for(int i = 0; i < (1 << (h + w - 1)); i++)
    {
        rep(j,h) rep(k,w) copy[j][k] = a[j][k];
        rep(j,w-1)
        {
            int tmp1 = (1 << j);
            if((i / tmp1) % 2 == 1)
            {
                swap_s(copy, j);
            }
        }
        for(int j = 0; j < h - 1; j++)
        {
            int tmp1 = (1 << (j + (w-1)));
            if((i/ tmp1) % 2 == 1)
            {
                swap(copy[j], copy[j+1]);
            }
        }
        bool ok = true;
        rep(j,h) rep(k,w)
        {
            if(copy[j][k] != b[j][k]) ok = false;
        }
        if(ok)
        {
            int tmp = 0;
            rep(j,(h+w-2))
            {
                int tmp1 = 1 << j;
                if((i / tmp1) % 2 == 1) tmp++;
            }
            ans = min(tmp, ans);
        }
    }
    if(ans == inf) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}