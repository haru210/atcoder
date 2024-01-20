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

//各マス1回は見れる
//
int main()
{
    int h,w,k;
    int ans = inf;
    cin >> h >> w >> k;
    string s[h];
    int yoko_s[h][w] = {};
    int tate_s[w][h] = {};
    rep(i,h) cin >> s[i];
    //1からnマスのoの数を累積和することで埋められるかだけ確認すればよい
    rep(i,h)
    {
        rep(j,w)
        {
            int tmp = 0;
            if(s[i][j] == 'o') tmp = 1;
            if(j == 0) yoko_s[i][j] = tmp;
            else yoko_s[i][j] = yoko_s[i][j-1] + tmp; 
        }
    }
    rep(j,w)
    {
        rep(i,h)
        {
            int tmp = 0;
            if(s[i][j] == 'o') tmp = 1;
            if(i == 0) tate_s[j][i] = tmp;
            else tate_s[j][i] = tate_s[j][i-1] + tmp;
        }
    }
    //横
    int yoko[h][w] = {};
    rep(i,h)
    {
        int start = 0;
        rep(j,w)
        {
            if(j < k)
            {
                if(s[i][j] == 'x') start = j + 1;
            }
            if(j == (k - 1))
            {
                yoko[i][j] = (j + 1) - start;
            }
            if(j >= k)
            {
                if(s[i][j] != 'x')
                {
                    yoko[i][j] = yoko[i][j-1] + 1;
                } 
                else
                {
                    yoko[i][j] = 0;
                }
            }
            if(yoko[i][j] >= k)
            {
                //(i,j - (k-1))から(i,j)をチェック
                int tmp;
                if(j - k < 0) tmp = k - yoko_s[i][j];
                tmp = k - (yoko_s[i][j] - yoko_s[i][j - k]);
                ans = min(ans,tmp);
            }
        }
    }
    //縦
    int tate[w][h] = {};
    rep(j,w)
    {
        int start = 0;
        rep(i,h)
        {
            if(i < k)
            {
                if(s[i][j] == 'x') start = i + 1;
            }
            if(i == (k - 1))
            {
                tate[j][i] = (i + 1) - start;
            }
            if(i >= k)
            {
                if(s[i][j] != 'x')
                {
                    tate[j][i] = tate[j][i-1] + 1;
                } 
                else
                {
                    tate[j][i] = 0;
                }
            }
            if(tate[j][i] >= k)
            {
                int tmp;
                if(i - k < 0) tmp = k - tate[j][i];
                tmp = k - (tate_s[j][i] - tate_s[j][i - k]);
                ans = min(ans,tmp);
            }

        }
    }
    if(ans == inf) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}